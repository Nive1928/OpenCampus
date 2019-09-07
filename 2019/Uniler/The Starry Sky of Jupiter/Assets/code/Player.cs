using UnityEngine;
using System.Collections;
using System;
using UnityEngine.Networking;

public class Player : NetworkBehaviour
{
    // 移動スピード
    public float speed = 2;
    int WallLR = 0;
    int WallUD = 0;
    float x;
    float y;

    void Update()
    {

        if (!isLocalPlayer)
        {
            return;

        }

        // 右左方向を十字キーで決定
        x = Input.GetAxisRaw("Horizontal");

        //右に行こうとして右が壁なら動かない
        if (WallLR == 1 && x == 1)
        {
            x = 0;
        }
        //左に動こうとして左が壁なら動かない
        else if (WallLR == 2 && x == -1)
        {
            x = 0;
        }

        // 上下方向を十字キーで決定
        y = Input.GetAxisRaw("Vertical");

        //上に行こうとして上が壁なら動かない
        if (WallUD == 1 && y == 1)
        {
            y = 0;
        }
        //下に行こうとして下が壁なら動かない
        else if (WallUD == 2 && y == -1)
        {
            y = 0;
        }

        //斜め移動しようとした際に斜め移動を取り消す
        if (x == 1 && y == 1 || x == 1 && y == -1 || x == -1 && y == 1 || x == -1 && y == -1)
        {
            x = 0;
            y = 0;
        }


        // 移動する向きを求める
        Vector2 direction = new Vector2(x, y).normalized;

        // 移動する向きとスピードを代入する
        Vector2 velocity = direction * speed;
        //GetComponent<Rigidbody2D>().velocity=dorection*speed;

        //----------------------------------------------------------
        velocity = velocity / 9;
        transform.Translate(velocity);

        CmdSyncTransform(transform.position, transform.rotation);
        //---------------------------------------------------------

        if (Input.GetKeyDown(KeyCode.Space))
        {

        }
    }

    //当たり判定(接触時)
    void OnTriggerEnter2D(Collider2D other)
    {
        //タグが壁なら壁に当たった時の行動をとる
        if (other.tag == "Wall")
        {
            switch (x)
            {
                //右方向に進んでいてぶつかったので右に壁がある
                case 1:
                    WallLR = 1;
                    break;

                //左方向に進んでいてぶつかったので左に壁がある
                case -1:
                    WallLR = 2;
                    break;
            }

            switch (y)
            {
                //上方向に進んでいてぶつかったので上に壁がある
                case 1:
                    WallUD = 1;
                    break;

                //下方向に進んでいてぶつかったので下に壁がある
                case -1:
                    WallUD = 2;
                    break;
            }
        }

        if (other.name == "HP collider")
        {

        }
    }

    //当たり判定(離れた時)
    void OnTriggerExit2D(Collider other)
    {
        //壁から離れたら壁判定初期化
        if (other.tag == "Wall")
        {
            WallLR = 0;
            WallUD = 0;
        }

        if (other.name == "HP collider")
        {

        }
    }

    //camera2とdamageスクリプトのtargetという変数に位置情報を代入
    public override void OnStartLocalPlayer()
    {
        Camera.main.GetComponent<camera2>().target = transform;
        Camera.main.GetComponent<damage>().target = transform;
    }

    [Command]
    void CmdSyncTransform(Vector3 position, Quaternion rotation)
    {
        //各接続に対して情報を送信する
        foreach (var conn in NetworkServer.connections)
        {
            //無効なコネクションは無視する

            if (conn == null || !conn.isReady)
                continue;

            //情報発信元への送り返しを防ぐため,自分へのコネクションは無視する
            if (conn == connectionToClient)
                continue;

            //このコネクションに対して位置情報を送信
            TargetSyncTransform(conn, position, rotation);
        }
    }

    [TargetRpc]

    void TargetSyncTransform(NetworkConnection target, Vector3 position, Quaternion rotation)
    {
        transform.SetPositionAndRotation(position, rotation);

    }
}
//[Command]
//void misssile()
//{
//Debug.Log("Sync CHK");

//各接続に対して情報を送信する
// foreach (var conn in NetworkServer.connections)
// {
//無効なコネクションは無視する

//if (conn == null || !conn.isReady)
//      continue;

//情報発信元への送り返しを防ぐため,自分へのコネクションは無視する
//    if (conn == connectionToClient)
//     continue;
//  }
//}
