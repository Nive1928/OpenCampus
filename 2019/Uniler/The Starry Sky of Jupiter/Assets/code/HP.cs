using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HP : MonoBehaviour { 

    private GameObject MainCamera = null;
    private Vector3 offset = Vector3.zero;

    // Start is called before the first frame update
    void Start()
    {
        MainCamera = GameObject.FindGameObjectWithTag("MainCamera");
        offset = transform.position - MainCamera.transform.position;
    }

    void LateUpdate()
    {
        Vector3 newPosition = transform.position;
        newPosition.x = MainCamera.transform.position.x + offset.x;
        newPosition.y = MainCamera.transform.position.y + offset.y;
        newPosition.z = MainCamera.transform.position.z + offset.z;
        transform.position = newPosition;
    }
}
