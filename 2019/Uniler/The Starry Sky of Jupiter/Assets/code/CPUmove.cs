using UnityEngine;
using System.Collections;
using System;
using UnityEngine.Networking;

public class CPUmove : NetworkBehaviour
{
    // 移動スピード
    public float speed = 2;
    int WallLR = 0;
    int WallUD = 0;
    float x = 0;
    float y = 0;
    int ram = 0;
    int Count = 0;
    int check = 0;
    public int q = 0;

    void Update()
    {
        if (x == 0 && y == 0 && Count == 0)
        {
            //前回の行動方向をcheckに代入
            check = ram;
            //4/1の確率で移動方向決定
            ram = UnityEngine.Random.Range(0, 4);

            //前回と同じ方向に進もうとした時(左右)に上下に切り替え、もう一度ランダム
            if (check == 0 && ram == 1 || check == 1 && ram == 0)
            {
                ram = UnityEngine.Random.Range(2, 4);
            }

            //前回と同じ方向に進もうとした時(上下)に左右に切り替え、もう一度ランダム
            if (check == 2 && ram == 3 || check == 3 && ram == 2)
            {
                ram = UnityEngine.Random.Range(0, 2);
            }
        }

        // 右左の行動決定
        switch (ram)
        {
            case 0:
                x = -1;
                Count++;
                //150回繰り返すまで固定
                if (Count == 150)
                {
                    x = 0;
                    Count = 0;
                }
                break;

            case 1:
                x = 1;
                Count++;
                //150回繰り返すまで固定
                if (Count == 150)
                {
                    x = 0;
                    Count = 0;
                }
                break;
        }

        //右方向に決定し右が壁の時、左向きに変更し、次回以降左に決定するようにする
        if (WallLR == 1 && x == 1)
        {
            x = -1;
            ram = 0;
        }
        //左方向に決定し左が壁の時、右向きに変更し、次回以降右に決定するようにする
        else if (WallLR == 2 && x == -1)
        {
            x = 1;
            ram = 1;
        }

        // 上下の行動決定
        switch (ram)
        {
            case 2:
                y = -1;
                Count++;
                //250回繰り返すまで固定(上下のほうが長いため繰り返す回数が多い)
                if (Count == 250)
                {
                    Count = 0;
                    y = 0;
                }
                break;

            case 3:
                y = 1;
                Count++;
                //250回繰り返すまで固定(上下のほうが長いため繰り返す回数が多い)
                if (Count == 250)
                {
                    Count = 0;
                    y = 0;
                }
                break;
        }

        //上方向に決定し上が壁の時、下向きに変更し、次回以降下に決定するようにする
        if (WallUD == 1 && y == 1)
        {
            y = -1;
            ram = 2;
        }

        //下方向に決定し下が壁の時、上向きに変更し、次回以降上に決定するようにする
        else if (WallUD == 2 && y == -1)
        {
            y = 1;
            ram = 3;
        }

        //斜め移動しようとした際に斜め移動を取り消す(CPUでは起きるはずがないが一応の処理)
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

        velocity = velocity / 9;
        transform.Translate(velocity);

        CmdSyncTransform(transform.position, transform.rotation);
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
            q = 1;
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
            q = 0;
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
