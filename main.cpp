#include<Windows.h>
//�E�C���h�E�v���V�[�W��
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//���b�Z�[�W�ɉ����ăQ�[���ŗL�̏������s��
	switch (msg) {
		//�E�C���h�E���j�����ꂽ
	case WM_DESTROY:
		//OS�ɑ΂���,�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}

	//�W���̃��b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}


//Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//�E�C���h�E�T�C�Y
	const int window_width = 1280;//����
	const int window_height = 720;//�c��

	//�E�C���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;		//�E�C���h�E�v���V�[�W����ݒ�
	w.lpszClassName = L"DirectXGame";			//�E�C���h�E�N���X��
	w.hInstance = GetModuleHandle(nullptr);		//�E�C���h�E�n���h��
	w.hCursor = LoadCursor(NULL, IDC_ARROW);	//�J�[�\���w��

	//�E�C���h�E�N���X��OS�ɓo�^����
	RegisterClassEx(&w);
	//�E�C���h�E�T�C�Y{ X���W Y���W ���� �c�� }
	RECT wrc = { 0,0,window_width,window_height };
	//�����ŃT�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//�E�C���h�E�I�u�W�F�N�g�̐���
	HWND hwnd = CreateWindow(w.lpszClassName,	//�N���X��
		L"DirectXGame",			//�^�C�g���o�[�̕���
		WS_OVERLAPPEDWINDOW,	//�W���I�ȃE�C���h�E�X�^�C��
		CW_USEDEFAULT,			//�\��X���W(OS�ɔC����)
		CW_USEDEFAULT,			//�\��Y���W(OS�ɔC����)
		wrc.right - wrc.left,	//�E�C���h�E����
		wrc.bottom - wrc.top,	//�E�C���h�E�c��
		nullptr,				//�e�E�C���h�E�p�l��
		nullptr,				//���j���[�n���h��
		w.hInstance,			//�Ăяo���A�v���P�[�V�����n���h��
		nullptr);				//�I�v�V����

	//�E�C���h�E�\����Ԃɂ���
	ShowWindow(hwnd, SW_SHOW);
	//�R���\�[���ւ̕����o��
	OutputDebugStringA("Hello,DirectX!!\n");

	MSG  msg{};		//���b�Z�[�W

	//DirectX���������� ��������


	//DirectX���������� �����܂�


	//�Q�[�����[�v
	while (true) {
		//���b�Z�[�W������?
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);//�L�[���̓��b�Z�[�W�̏���
			DispatchMessage(&msg);//�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
		}


		//X�{�^���ŏI�����b�Z�[�W��������Q�[�����[�v�𔲂���
		if (msg.message == WM_QUIT) {
			break;
		}
		//DirectX���t���[�������@��������

		//DirectX���t���[�������@�����܂�
	}

	//�E�C���h�E�N���X��o�^����
	UnregisterClass(w.lpszClassName, w.hInstance);
	return 0;
}
