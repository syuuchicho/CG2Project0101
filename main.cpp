#include<Windows.h>
//ウインドウプロシージャ
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//メッセージに応じてゲーム固有の処理を行う
	switch (msg) {
		//ウインドウが破棄された
	case WM_DESTROY:
		//OSに対して,アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}

	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}


//Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//ウインドウサイズ
	const int window_width = 1280;//横幅
	const int window_height = 720;//縦幅

	//ウインドウクラスの設定
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;		//ウインドウプロシージャを設定
	w.lpszClassName = L"DirectXGame";			//ウインドウクラス名
	w.hInstance = GetModuleHandle(nullptr);		//ウインドウハンドル
	w.hCursor = LoadCursor(NULL, IDC_ARROW);	//カーソル指名

	//ウインドウクラスをOSに登録する
	RegisterClassEx(&w);
	//ウインドウサイズ{ X座標 Y座標 横幅 縦幅 }
	RECT wrc = { 0,0,window_width,window_height };
	//自動でサイズを補正する
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//ウインドウオブジェクトの生成
	HWND hwnd = CreateWindow(w.lpszClassName,	//クラス名
		L"DirectXGame",			//タイトルバーの文字
		WS_OVERLAPPEDWINDOW,	//標準的なウインドウスタイル
		CW_USEDEFAULT,			//表示X座標(OSに任せる)
		CW_USEDEFAULT,			//表示Y座標(OSに任せる)
		wrc.right - wrc.left,	//ウインドウ横幅
		wrc.bottom - wrc.top,	//ウインドウ縦幅
		nullptr,				//親ウインドウパネル
		nullptr,				//メニューハンドル
		w.hInstance,			//呼び出しアプリケーションハンドル
		nullptr);				//オプション

	//ウインドウ表示状態にする
	ShowWindow(hwnd, SW_SHOW);
	//コンソールへの文字出力
	OutputDebugStringA("Hello,DirectX!!\n");

	MSG  msg{};		//メッセージ

	//DirectX初期化処理 ここから


	//DirectX初期化処理 ここまで


	//ゲームループ
	while (true) {
		//メッセージがある?
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);//キー入力メッセージの処理
			DispatchMessage(&msg);//プロシージャにメッセージを送る
		}


		//Xボタンで終了メッセージが来たらゲームループを抜ける
		if (msg.message == WM_QUIT) {
			break;
		}
		//DirectX毎フレーム処理　ここから

		//DirectX毎フレーム処理　ここまで
	}

	//ウインドウクラスを登録解除
	UnregisterClass(w.lpszClassName, w.hInstance);
	return 0;
}
