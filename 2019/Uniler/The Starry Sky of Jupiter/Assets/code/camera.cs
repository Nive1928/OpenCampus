using UnityEngine;
using System.Collections;
using System;
using UnityEngine.Networking;

public class camera : NetworkBehaviour
{
    // 移動スピード
    public float speed = 5;
    public int z = 0;
    public int a = 0;
    float x;
    float y;

    void Update()
    {
        // 右・左
        x = Input.GetAxisRaw("Horizontal");

        if (z == 1 && x == 1) {
            x = 0;
        }
        else if(z == 2 && x == -1){
            x = 0;
        } 

        // 上・下
        y = Input.GetAxisRaw("Vertical");

        if (a == 1 && y == 1){
            y = 0;
        }
        else if(a == 2 && y == -1){
            y = 0;
        }

        if(x == 1 && y == 1 || x == 1 && y == -1 || x == -1 && y == 1 || x == -1 && y == -1){
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


        if (z == 1 && x == -1){
            z = 0;
        }
        else if(z == 2 && x == 1){
            z = 0;
        }
        else if(a == 1 && y == -1){
            a = 0;
        }
        else if(a == 2 && y == 1){
            a = 0;
        }
    }
    void OnTriggerEnter2D(Collider2D c){
        switch (x) {
            case 1:
                z = 1;
            break;
            case -1:
                z = 2;
            break;
        }
        switch (y){
            case 1:
                a = 1;
            break;
            case -1:
                a = 2;
            break;
        }
    }
}