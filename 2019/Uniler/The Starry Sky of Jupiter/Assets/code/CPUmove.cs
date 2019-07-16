using UnityEngine;
using System.Collections;
using System;
using UnityEngine.Networking;

public class CPUmove : NetworkBehaviour
{
    // 移動スピード
    public float speed = 5;
    public int z = 0;
    public int a = 0;
    float x;
    float y;
    int ram = 0;
    int v = 0;
    int r = 0;
    int s = 0;
    int g = 0;

    void Update()
    {
        Debug.Log("Updata");

        ram = UnityEngine.Random.Range(0, 2);

        if (g == 0 && ram == 0 && z == 1 || g == 0 && ram == 0 && z == 2)
        {
            v = UnityEngine.Random.Range(0, 2);
            g = 1;
        }
        if(g == 0 && ram == 1 && a == 1 || g == 0 && ram == 1 && a == 1)
        {
            r = UnityEngine.Random.Range(0, 2);
            g = 1;
        }
        // 右・左
        switch (v)
        {
            case 0:
                x = -1;
                s += 1;
                if (s == 50)
                {
                    g = 0;
                    s = 0;
                }
                break;
            case 1:
                x = 1;
                s += 1;
                if (s == 50)
                {
                    g = 0;
                    s = 0;
                }
                break;
        }

        if (z == 1 && x == 1)
        {
            x = 0;
            g = 0;
        }
        else if (z == 2 && x == -1)
        {
            x = 0;
            g = 0;
        }

        // 上・下
        switch (r)
        {
            case 0:
                y = -1;
                s += 1;
                if (s == 50)
                {
                    g = 1;
                    s = 0;
                    y = 0;
                }
                break;
            case 1:
                y = 1;
                s += 1;
                if (s == 50)
                {
                    g = 1;
                    s = 0;
                    y = 0;
                }
                break;
        }

        if (a == 1 && y == 1)
        {
            y = 0;
            g = 0;
        }
        else if (a == 2 && y == -1)
        {
            y = 0;
            g = 0;
        }
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

        Debug.Log("Change xy");
        CmdSyncTransform(transform.position, transform.rotation);

        if (z == 1 && x == -1)
        {
            z = 0;
        }
        else if (z == 2 && x == 1)
        {
            z = 0;
        }
        else if (a == 1 && y == -1)
        {
            a = 0;
        }
        else if (a == 2 && y == 1)
        {
            a = 0;
        }
        Debug.Log("End");
    }
    void OnTriggerEnter2D(Collider2D c)
    {
        switch (x)
        {
            case 1:
                z = 1;
                break;
            case -1:
                z = 2;
                break;
        }
        switch (y)
        {
            case 1:
                a = 1;
                break;
            case -1:
                a = 2;
                break;
        }
    }

    [Command]
    void CmdSyncTransform(Vector3 position, Quaternion rotation)
    {
        Debug.Log("Sync CHK");

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
        Debug.Log("Sync go");
        transform.SetPositionAndRotation(position, rotation);

    }
    public override void OnStartLocalPlayer()
    {
        Camera.main.GetComponent<camera2>().target = transform;
        Camera.main.GetComponent<damage>().target = transform;
    }

}