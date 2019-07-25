#pragma once

/*

各キャラクターの構造体を格納するヘッダーファイル

*/

struct Player {		//プレイヤーの構造体データ
	int HP;
	int x;
	int y;
	int score;
};

struct Enemy {		//敵キャラクターの構造体データ
	int HP;
	int Speed;
	int Strength;
	int x;
	int y;
	int enemyType;
	int score;
};
