#pragma once

#include <curses.h>
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "screen.h"

/*

��ʕ`�ʂɊւ���w�b�_�[�t�@�C��

*/

// �^�C�g����ʂ̕\��
void DrawTitle() {

	Scr_start();
	mvaddstr(25, 30, "STAGE SELECT : Press 1(easy) Press2(normal) Press3(hard)");
}


//�@�Q�[���I�[�o�[��ʂ̕\��
void DrawGameover() {
	Scr_gameover();
	mvaddstr(25, 40, "q�{�^���������ƃ^�C�g���ɖ߂�܂��B");
}

// �Q�[���N���A��ʂ̕\��
void DrawGameclear() {
	Scr_gameclear();
	mvaddstr(25, 40, "q�{�^���������ƃ^�C�g���ɖ߂�܂��B");
	mvaddstr(26, 40, "w�{�^���������ƃQ�[�����I�����܂��B");
}


//�@�X�e�[�^�X�\��
void DrawStatus(int playerHP) {
	for (int i = 0; i < playerHP; i++) {
		addstr("��");
	}
}

// �}�b�v�̕`�ʊ֐�
void DrawMap() {
	attrset(0);
	for (int y = 0; y < MAP_H; y++) {
		for (int x = 0; x < MAP_W; x++) {
			if (map[y][x] == 1) {
				mvaddstr(MAP_Y + y, MAP_X + x * 2, "��");
			}
			else if (map[y][x] == 3) {
				attrset(COLOR_PAIR(4));
				mvaddstr(MAP_Y + y, MAP_X + x * 2, "��");
				attrset(0);
			}
		}
	}
}

// �^�C�g�����̕`�ʊ֐�
void DrawAscii() {
	for (int y = 0; y < ASCII_H; y++) {
		for (int x = 0; x < ASCII_W; x++) {
			if (scr[y][x] == 1) {
				mvaddstr(ASCII_Y + y, ASCII_X + x * 2, "��");
			}
		}
	}
}

//  �Q�[����ʂ̕\��
void DrawAll() {
	// ��ʂ��N���A
	erase();

	// ��ʂ̕`��
	DrawMap();
	attrset(COLOR_PAIR(1));			// �F1 ���g��
	mvaddstr(player.y, player.x, "��");
	attrset(0);

	mvaddstr(24, 6, "Dialog :");
	mvaddstr(2, 38 * 2, "Player HP ");
	attrset(COLOR_PAIR(2));
	DrawStatus(player.HP);
	attrset(COLOR_PAIR(0));
	mvprintw(4, 38 * 2, "Score : %d", player.score);

	mvaddstr(6, 38 * 2, "�\�\�\�\�\�\�\�\�\�\�\�\�\�\�\");
	mvaddstr(8, 42 * 2, "[ INFORMATION ]");
	attrset(COLOR_PAIR(1));
	mvaddstr(10, 38 * 2, "��");
	attrset(COLOR_PAIR(0));
	mvaddstr(10, 39 * 2, "�FPlayer");
	attrset(COLOR_PAIR(3));
	mvaddstr(12, 38 * 2, "��");
	attrset(COLOR_PAIR(4));
	mvaddstr(14, 38 * 2, "��");
	attrset(COLOR_PAIR(5));
	mvaddstr(16, 38 * 2, "��");
	attrset(COLOR_PAIR(0));
	mvaddstr(12, 39 * 2, "�FEnemyA�@attack 2�@ 200 Point");
	mvaddstr(14, 39 * 2, "�FEnemyB�@attack 3   300 Point");
	mvaddstr(16, 39 * 2, "�FEnemyC�@attack 5   500 Point");
	mvaddstr(18, 39 * 2, "�FItem              1000 Point");
	attrset(COLOR_PAIR(4));
	mvaddstr(18, 38 * 2, "��");
	attrset(COLOR_PAIR(0));

	mvaddstr(20, 39 * 2, "�@���@");
	mvaddstr(21, 39 * 2, "���@���@Move Player");
	mvaddstr(22, 39 * 2, "�@���@");
	mvaddstr(24, 39 * 2, "Avoid the enemies,");
	mvaddstr(26, 39 * 2, "and escape the Labyrinth.");
	mvaddstr(20, 33 * 2, "GOAL");
	refresh();
	//�@�G�L�����N�^�[�̕`��
	if (enemyExist[0] == 1) {
		if (enemy1.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy1.y, enemy1.x, "��");
		}
		else if (enemy1.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy1.y, enemy1.x, "��");
		}
		else if (enemy1.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy1.y, enemy1.x, "��");
		}
	}

	if (enemyExist[1] == 1) {
		if (enemy2.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy2.y, enemy2.x, "��");
		}
		else if (enemy2.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy2.y, enemy2.x, "��");
		}
		else if (enemy2.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy2.y, enemy2.x, "��");
		}
	}

	if (enemyExist[2] == 1) {
		if (enemy3.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy3.y, enemy3.x, "��");
		}
		else if (enemy3.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy3.y, enemy3.x, "��");
		}
		else if (enemy3.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy3.y, enemy3.x, "��");
		}
	}

	if (enemyExist[3] == 1) {
		if (enemy4.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy4.y, enemy4.x, "��");
		}
		else if (enemy4.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy4.y, enemy4.x, "��");
		}
		else if (enemy4.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy4.y, enemy4.x, "��");
		}
	}

	if (enemyExist[4] == 1) {
		if (enemy5.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy5.y, enemy5.x, "��");
		}
		else if (enemy5.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy5.y, enemy5.x, "��");
		}
		else if (enemy5.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy5.y, enemy5.x, "��");
		}
	}

	refresh();

	//�@�_�C�A���O�̕\��
	attrset(0);
	mvaddstr(24, 6, "Dialog :");

	if (player.HP <= 0) {
		mvaddstr(24, 14, "�y You died... Press AnyKey! �z");
		flag = 0;
	}
	else if (flag == 1) {
		mvprintw(24, 14, "�y �v���C���[��2�_���[�W�󂯂�! �z");
	}
	else if (flag == 2) {
		mvprintw(24, 14, "�y �v���C���[��3�_���[�W�󂯂�! �z");
	}
	else if (flag == 3) {
		mvprintw(24, 14, "�y �v���C���[��5�_���[�W�󂯂�! �z");
	}
	else if (flag == 4) {
		mvprintw(24, 14, "�y 1000�X�R�A�l���I �z");
	}

	refresh();
}