using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class MyNetworkManagerHUD : MonoBehaviour
{
    

    // ボタン等の主なUIを含むGameObject
    GameObject m_MainUIs;

    // 接続中であることを示すUIのGameObject
    GameObject m_ConnectingText;

    // 接続状態種別
    enum ConnectionState
    {


        // 純粋なサーバーとして起動中
        Server,
        // ホスト（サーバー兼クライアント）として起動中
        Host,
        // リモートクライアントとして接続確立済み
        RemoteClientConnected,
        // リモートクライアントとして接続試行中
        RemoteClientConnecting,
        // 接続なし
        Nothing,
    }

    // ネットワーク接続の状態を取得する
    ConnectionState GetConnectionState()
    {
        // サーバーが起動しているか？
        if (NetworkServer.active)
        {
            // クライアントとして接続しているか？
            if (NetworkManager.singleton.IsClientConnected())
            {
                // ホストとして起動中
                return ConnectionState.Host;
            }
            else
            {
                // サーバーとして起動中
                return ConnectionState.Server;
            }
        }
        // クライアントとして接続しているか？
        else if (NetworkManager.singleton.IsClientConnected())
        {
            // リモートクライアントとして接続確立済み
            return ConnectionState.RemoteClientConnected;
        }
        else
        {
            NetworkClient client = NetworkManager.singleton.client;

            // Connectionが存在するか？
            if (client != null && client.connection != null && client.connection.connectionId != -1)
            {
                // 接続試行中
                return ConnectionState.RemoteClientConnecting;
            }
            else
            {
                // 接続なし（何もしていない）
                return ConnectionState.Nothing;
            }
        }
    }

    void Start()
    {
        Debug.Log("HUD start");

        m_MainUIs = GameObject.Find("MainUIs");
        m_ConnectingText = GameObject.Find("ConnectingText");
    }

    void Update()
    {
        ConnectionState state = GetConnectionState();

        // 接続試行中
        if (state == ConnectionState.RemoteClientConnecting)
        {
            m_MainUIs.SetActive(false);
            m_ConnectingText.SetActive(true);

            // Escapeキーで接続中止
            if (Input.GetKeyDown(KeyCode.Escape))
            {
                NetworkManager.singleton.StopHost();
            }
        }
        else
        {
            m_MainUIs.SetActive(true);
            m_ConnectingText.SetActive(false);
        }
    }

    // 「サーバーとして起動」ボタンが押された時の処理
    public void OnServerButtonClicked()
    {
        Debug.Log("Server start");
        NetworkManager.singleton.StartServer();
    }

    // 「ホストとして起動」ボタンが押された時の処理
    public void OnHostButtonClicked()
    {
        Debug.Log("Host start");
        NetworkManager.singleton.StartHost();
    }

    // 「サーバーへ接続(クライアント)」ボタンが押された時の処理
    public void OnClientButtonClicked()
    {
        Debug.Log("Client start");
        InputField input = GameObject.Find("ServerAddressInputField").GetComponent<InputField>();
        NetworkManager.singleton.networkAddress = input.text;
        NetworkManager.singleton.StartClient();
    }
}