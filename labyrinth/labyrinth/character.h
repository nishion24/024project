#pragma once

/*

�e�L�����N�^�[�̍\���̂��i�[����w�b�_�[�t�@�C��

*/

struct Player {		//�v���C���[�̍\���̃f�[�^
	int HP;
	int x;
	int y;
	int score;
};

struct Enemy {		//�G�L�����N�^�[�̍\���̃f�[�^
	int HP;
	int Speed;
	int Strength;
	int x;
	int y;
	int enemyType;
	int score;
};
