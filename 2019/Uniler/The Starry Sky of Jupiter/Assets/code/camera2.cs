using System;
using UnityEngine;
using System.Collections;

public class camera2 : MonoBehaviour
{
        public Transform target;
        public Vector3 offset = new Vector3(0f, 0f,-10f);


        private void Update()
        {
            transform.position = target.position + offset;
        }
}

