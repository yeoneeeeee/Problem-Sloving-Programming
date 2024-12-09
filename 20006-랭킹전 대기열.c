#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int room_num = 0;
int room_infor[300] = { 0 };
int room_list_lv[300][300] = { 0 };
char room_list_name[300][300][17];

int main() {
    int p_lv;
    char p_name[17];

    int p, m;
    scanf_s("%d %d", &p, &m);

    for (int i = 0; i < p; i++) {
        scanf_s("%d %16s", &p_lv, p_name, (unsigned)_countof(p_name));

        int assigned = 0;

        for (int j = 0; j < room_num; j++) {
            if (abs(room_list_lv[j][0] - p_lv) <= 10 && room_infor[j] < m) {
                room_list_lv[j][room_infor[j]] = p_lv;
                strncpy_s(room_list_name[j][room_infor[j]], 17, p_name, _TRUNCATE);
                room_infor[j]++;
                assigned = 1;
                break;
            }
        }

        if (!assigned) {
            room_list_lv[room_num][0] = p_lv;
            strncpy_s(room_list_name[room_num][0], 17, p_name, _TRUNCATE);
            room_infor[room_num]++;
            room_num++;
        }
    }

    for (int i = 0; i < room_num; i++) {
        for (int j = 0; j < room_infor[i] - 1; j++) {
            for (int k = j + 1; k < room_infor[i]; k++) {
                if (strcmp(room_list_name[i][j], room_list_name[i][k]) > 0) {
                    char temp_name[17];
                    int temp_lv;

                    strncpy_s(temp_name, 17, room_list_name[i][j], _TRUNCATE);
                    strncpy_s(room_list_name[i][j], 17, room_list_name[i][k], _TRUNCATE);
                    strncpy_s(room_list_name[i][k], 17, temp_name, _TRUNCATE);

                    temp_lv = room_list_lv[i][j];
                    room_list_lv[i][j] = room_list_lv[i][k];
                    room_list_lv[i][k] = temp_lv;
                }
            }
        }
    }

    for (int i = 0; i < room_num; i++) {
        if (room_infor[i] == m)
            printf("Started!\n");
        else
            printf("Waiting!\n");

        for (int j = 0; j < room_infor[i]; j++) {
            printf("%d %s\n", room_list_lv[i][j], room_list_name[i][j]);
        }
    }

    return 0;
}