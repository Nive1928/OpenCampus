using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class damage : MonoBehaviour
{
    int x = 1;
    public Transform target;
    public Vector3 offset = new Vector3(0f, 0f, -10f);


    private void LateUpdate()
    {
        transform.position = target.position + offset;
    }

    void OnTriggerEnter2D(Collider2D c)
    {
        GameObject obj = GameObject.Find("HP ("+x+")");
        Destroy(obj);
        x = x + 1;
        GameObject objet = GameObject.Find("HP ("+x+")");
        Destroy(objet);
        x = x + 1;
    }

        

    void Update()
    {
        if (x >= 20)
        {
            GameObject plaryer = GameObject.Find("Player(Clone)");
            Destroy(plaryer);
            Destroy(this.gameObject);
        }
    }
}

