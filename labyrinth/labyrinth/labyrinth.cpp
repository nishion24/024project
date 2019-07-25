// labyrinth.cpp : ���̃t�@�C���ɂ� 'main' �֐����܂܂�Ă��܂��B�v���O�������s�̊J�n�ƏI���������ōs���܂��B
//

//#include "pch.h"
#include <iostream>

#include "stdafx.h"
#include <curses.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <future>

#include "InputOut.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "screen.h"
#include "draw.h"

// �֐��̃v���g�^�C�v�錾
void play_loop();
void titleSet();

// �O���[�o���ϐ���`
bool title = true;
bool playing = true;
bool CLEAR = false;
int Mapflag;

// ���C�����\�b�h
int main()
{

	if (initscr() == NULL) {	//������
		return 1;
	}

START:
	erase();
	playing = true;
	title = true;

	// �F�̏��� (1:�V�A�� 2:�� 3:�� 4:�� 5:�}�[���^)
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);


	//����L�[�̎󂯕t������
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);

	//TITLE:
	while (title) {

		// �^�C�g����ʂ̕\���ƑI�񂾃L�[�ɂ�鏉���ݒ�
		titleSet();

	}


	//GAME:
	// �X���b�h�쐬
	auto th_game = std::thread([] {play_loop(); });
	std::mt19937 mt;
	std::uniform_real_distribution<double> ud(0.0, 1.0);

	while (true) {

		DrawAll();		// ��ʂ̕`��
		Control();		// �L�[����

		// �A�C�e���l������
		if (map[Y][X] == 3) {
			map[Y][X] = 0;
			player.score += 1000;
			flag = 4;

		}

		//�@�Q�[���N���A����
		if (map[Y][X] == 2) {
			CLEAR = true;
			Output("score.txt", player.score);
			break;
		}

		// �Q�[���I�[�o�[����
		if (player.HP <= 0) {

			playing = false;
			th_game.join();

			erase();
			DrawGameover();
			Output("score.txt", player.score);

			while (1) {
				int key2 = getch();
				if (key2 == 'q') {
					goto START;
				}
			}
		}

	}

	playing = false;  // �Q�[���v���C���ł���Ƃ����t���O���I�t
	th_game.join();	  // �X���b�h�I���҂�

	//CLEAR:
	if (CLEAR == true) {
		erase();
		DrawGameclear();

		while (1) {
			int key = getch();
			if (key == 'q') {
				CLEAR = false;
				goto START;
			}
			else if (key == 'w') {
				break;
			}
		}
	}

	endwin();

	return 0;
}


// �X���b�h���̏��������[�v
void play_loop() {
	while (playing) {
		if (enemyExist[0] == 1) {
			enemymove();
		}
		if (enemyExist[1] == 1) {
			enemymove2();
		}
		if (enemyExist[2] == 1) {
			enemymove3();
		}
		if (enemyExist[3] == 1) {
			enemymove4();
		}
		if (enemyExist[4] == 1) {
			enemymove5();
		}

		DrawAll();
		std::this_thread::sleep_for(std::chrono::milliseconds(70));		// �X�s�[�h����
	}
}


void titleSet() {
	//������
	Mapflag = 0;
	DrawTitle();


	//�L�[�󂯕t��
	int key = getch();

	switch (key) {
	case '1':
		MapChange1();
		title = false;
		Mapflag = 1;

		//�X�e�[�^�X�̃Z�b�g
		//�����Œ��x�}�b�v�̓G�z�u
		player = StatusSet();
		enemy1 = StatusSetB(28, 18);
		enemy2 = StatusSetC(28, 1);
		enemy3 = StatusSetA(10, 14);
		// 1�ɂ���ƓG�z�u
		enemyExist[0] = 1;
		enemyExist[1] = 1;
		enemyExist[2] = 1;
		enemyExist[3] = 0;
		enemyExist[4] = 0;
		break;

	case '2':
		MapChange2();
		title = false;
		Mapflag = 2;

		//�X�e�[�^�X�̃Z�b�g
		//�����Œ���x�}�b�v�̓G�z�u
		player = StatusSet();
		enemy1 = StatusSetB(28, 18);
		enemy2 = StatusSetC(28, 1);
		enemy3 = StatusSetB(14, 4);
		enemy4 = StatusSetA(10, 16);
		enemyExist[0] = 1;
		enemyExist[1] = 1;
		enemyExist[2] = 1;
		enemyExist[3] = 1;
		enemyExist[4] = 0;
		break;

	case '3':
		MapChange3();
		title = false;
		Mapflag = 3;

		//�X�e�[�^�X�̃Z�b�g
		//�����ō���x�}�b�v�̓G�z�u
		player = StatusSet();
		enemy1 = StatusSetC(28, 18);
		enemy2 = StatusSetC(28, 1);
		enemy3 = StatusSetA(6, 14);
		enemy4 = StatusSetB(10, 1);
		enemy5 = StatusSetA(20, 19);
		enemyExist[0] = 1;
		enemyExist[1] = 1;
		enemyExist[2] = 1;
		enemyExist[3] = 1;
		enemyExist[4] = 1;
		break;

	default:
		refresh();
		break;

	}
}