#pragma once

#include <Windows.h>
//#include "stdafx.h"
//#include "pch.h"
#include "character.h"

/*

�t�@�C������Ɋւ���w�b�_�[�t�@�C��

*/

#define BUFFSIZE 1024
#define DAYS	 365
#define CHARBUFF 124


// ���݂̃f�B���N�g�����擾
void getGurrentDirectory(char *currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

//�@�t�@�C���̓ǂݍ���
int getIntFromINI(const char* section, const char* para, const char* file, int defaultValue) {

	int num;

	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);

	char sect[CHARBUFF];
	sprintf_s(sect, section);
	char keyWord[CHARBUFF];
	sprintf_s(keyWord, para);
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, file, currentDirectory);
	//fprintf(stdout, "%s , %d\n", settingFile, GetPrivateProfileInt(section, keyWord, -1, settingFile));

	num = GetPrivateProfileInt(section, keyWord, -1, settingFile);

	return num;
}

//���ʂ̏o��
void Output(const char* fileName, int playerscore) {
	FILE* fp;
	errno_t error;
	char final_score[BUFFSIZE];

	error = fopen_s(&fp, fileName, "w");
	if (error != 0)
		fprintf_s(stderr, "failed to open");
	else {
		sprintf_s(final_score, "�X�R�A �F %d�_", playerscore);
		fputs(final_score, fp);
		fclose(fp);
	}
}