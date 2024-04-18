#include <Novice.h>
#include "Function.h"

const char kWindowTitle[] = "GC2A_08_チョウ_テンロウ_AL3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Vector3 rotate{ 0.4f,1.43f,-0.8f };
	Matrix4x4 rotateMatrix_X = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateMatrix_Y = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateMatrix_Z = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateMatrix_XYZ = rotateMatrix_X * rotateMatrix_Y * rotateMatrix_Z;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0, 0, rotateMatrix_X, "RotateMatrix_X");
		MatrixScreenPrintf(0, kRowHeight * 5, rotateMatrix_Y, "RotateMatrix_Y");
		MatrixScreenPrintf(0, kRowHeight * 5 * 2, rotateMatrix_Z, "RotateMatrix_Z");
		MatrixScreenPrintf(0, kRowHeight * 5 * 3, rotateMatrix_XYZ, "RotateMatrix_XYZ");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}