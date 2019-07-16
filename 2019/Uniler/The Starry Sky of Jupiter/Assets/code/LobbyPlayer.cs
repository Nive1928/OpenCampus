using UnityEngine;
using UnityEngine.Networking;

public class LobbyPlayer : NetworkBehaviour
{
    void Update()
    {
        if (!isLocalPlayer)
            return;

        // Escapeキーで切断する
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            // 切断は、サーバーもクライアントもStopHost()でOK
            NetworkManager.singleton.StopHost();
        }
    }
}
