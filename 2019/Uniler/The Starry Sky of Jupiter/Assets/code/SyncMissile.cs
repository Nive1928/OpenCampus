using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class SyncMissile : NetworkBehaviour
{
    private void Start()
    {
    //チーム情報を保持したスクリプトへ問い合わせて保存


    }


    void Update()
    {

        if (!isLocalPlayer)
        {
            return;

        }

        if (Input.GetKeyDown(KeyCode.Space))
        {

            CmdSyncmissile(true);
        }    
    }

    [Command]
    void CmdSyncmissile(bool killer)
    {

        //各接続に対して情報を送信する
        foreach (var conn in NetworkServer.connections)
        {
            //無効なコネクションは無視する

            if (conn == null || !conn.isReady)
                continue;

            TargetSVmissile(conn,killer,transform.position);
        }

    }

    [TargetRpc]

    void TargetSVmissile(NetworkConnection target,bool killer,Vector2 position)
    {

    }
}
