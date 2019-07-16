using UnityEngine;
using UnityEngine.Networking;
using System.Collections;
using System;

public class Player : NetworkBehaviour
//MonoBehaviour
//NetworkBehaviour
{
    // 移動スピード
    public float speed = 5;

    int z = 0;
    int a = 0;
    float x;
    float y;

    private void Start()
    {
        //3D用コードを利用のため実行不可
        this.transform.Rotate(0.0f, 0.0f, 0);
    }

    public GameObject gameobject;
    void Update(){

        if (!isLocalPlayer){

            z = gameobject.GetComponent<camera>().z;
            a = gameobject.GetComponent<camera>().a;
            // 右・左
            x = Input.GetAxisRaw("Horizontal");

            if (z == 1 && x == 1)
            {
                x = 0;
            }
            else if (z == 2 && x == -1)
            {
                x = 0;
            }

            // 上・下
            y = Input.GetAxisRaw("Vertical");

            if (a == 1 && y == 1)
            {
                y = 0;
            }
            else if (a == 2 && y == -1)
            {
                y = 0;
            }

            if (x == 1 && y == 1 || x == 1 && y == -1 || x == -1 && y == 1 || x == -1 && y == -1)
            {
                x = 0;
                y = 0;
            }

            // 移動する向きを求める
            Vector2 direction = new Vector2(x, y).normalized;

            // 移動する向きとスピードを代入する
            GetComponent<Rigidbody2D>().velocity = direction * speed;

        }


        //角度怪しい

        //3Dコード利用のため実行不可
        CmdSyncTransform(transform.position, transform.rotation);

    }
    

    //位置情報をホストに送信するコマンド
    [Command]
    void CmdSyncTransform(Vector3 position, Quaternion rotation)
    {
        //各接続に対して情報を送信する
        foreach(var conn in NetworkServer.connections)
        {
            //無効なコネクションは無視する

            if (conn == null || !conn.isReady)
                continue;

            //情報発信元への送り返しを防ぐため,自分へのコネクションは無視する
            if (conn == connectionToClient)
                continue;

            //このコネクションに対して位置情報を送信
            TargetSyncTransform(conn, position,rotation);

        }


    }

    [TargetRpc]

void TargetSyncTransform(NetworkConnection target,Vector3 position, Quaternion rotation)
    {

        transform.SetPositionAndRotation(position,rotation);

    }
    
}