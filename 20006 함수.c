#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 300
#define MAX_NAME_LEN 17

char player_name[MAX_NAME_LEN];
char char_team[MAX_PLAYERS][MAX_PLAYERS][MAX_NAME_LEN];
int int_team[MAX_PLAYERS][MAX_PLAYERS];
int team_cnt = 0;
int team_idx[MAX_PLAYERS] = { 0 };
int num_players, team_size;

void assignPlayer(int level, const char* name) {
    int assigned = 0;

    for (int i = 0; i < team_cnt; i++) {
        int level_gap = int_team[i][0] - level;
        if (level_gap >= -10 && level_gap <= 10 && team_idx[i] < team_size) {
            int_team[i][team_idx[i]] = level;
            strncpy_s(char_team[i][team_idx[i]], MAX_NAME_LEN, name, MAX_NAME_LEN - 1);
            team_idx[i]++;
            assigned = 1;
            break;
        }
    }

    if (!assigned) {
        int_team[team_cnt][0] = level;
        strncpy_s(char_team[team_cnt][0], MAX_NAME_LEN, name, MAX_NAME_LEN - 1);
        team_idx[team_cnt]++;
        team_cnt++;
    }
}

void sortTeams() {
    for (int i = 0; i < team_cnt; i++) {
        for (int j = 0; j < team_idx[i]; j++) {
            for (int k = j + 1; k < team_idx[i]; k++) {
                if (strcmp(char_team[i][j], char_team[i][k]) > 0) {
                    char temp_name[MAX_NAME_LEN];
                    strncpy_s(temp_name, MAX_NAME_LEN, char_team[i][j], MAX_NAME_LEN - 1);
                    strncpy_s(char_team[i][j], MAX_NAME_LEN, char_team[i][k], MAX_NAME_LEN - 1);
                    strncpy_s(char_team[i][k], MAX_NAME_LEN, temp_name, MAX_NAME_LEN - 1);

                    int temp_level = int_team[i][j];
                    int_team[i][j] = int_team[i][k];
                    int_team[i][k] = temp_level;
                }
            }
        }
    }
}

void printTeams() {
    for (int i = 0; i < team_cnt; i++) {
        if (team_idx[i] == team_size) {
            printf("Started!\n");
        }
        else {
            printf("Waiting!\n");
        }
        for (int j = 0; j < team_idx[i]; j++) {
            printf("%d %s\n", int_team[i][j], char_team[i][j]);
        }
    }
}

int main() {
    if (scanf_s("%d %d", &num_players, &team_size) != 2) {
        fprintf(stderr, "Invalid input for number of players and team size\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        int level;
        if (scanf_s("%d %s", &level, player_name, MAX_NAME_LEN) != 2) {
            fprintf(stderr, "Invalid input for player %d\n", i + 1);
            return 1;
        }

        assignPlayer(level, player_name);
    }

    sortTeams();
    printTeams();

    return 0;
}
