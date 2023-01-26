#include <iostream>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <vector>
#include <random>

char arena[20][50] =       {{'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M'},
                            {'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M'}};

struct Entity {
    int x;
    int y;
    char s;  

    void render() {
        arena[y][x] = s;
    }
    void derender() {
        arena[y][x] = ' ';
    }

    Entity(int ix, int iy, char ic) {
        x = ix;
        y = iy;
        s = ic;
    }
};

bool stop = false;
int score = 0;
int fuel = 300;
int direction ='d';
bool end = false;
Entity p(15, 15, '@');
std::vector<Entity> enemyVec; 
std::vector<Entity> pointVec;
void movePlayer(char c);
void retry();
void startGame();

void printArena() {
    printf("\033[2J");
    printf("\033[H");
    std::cout << "Grab the fuel! (O) | WASD to move | C to quit |"; 
    for (int i = 0; i < 20; i++) {
        std::cout << "\r\n";
        for (int j = 0; j < 50; j++) {
            std::cout << arena[i][j];
            std::cout << ' ';
        }
    }
    std::cout << "\r\n" << "Score: " << std::to_string(score) << " | Fuel: " << std::to_string(fuel) << "\r\n";
}

void sleep(int t) {
    std::this_thread::sleep_for(std::chrono::milliseconds(t));
}

void inputLoop() {
    while(true) {
        if (end == true) break;
        direction = getchar();
    }
}

void gameLoop() {
    int pointTimer = 2;
    int enemyTimer = 1;
    // arcane random generator shit
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> enemyDistr(1, 18);
    std::uniform_int_distribution<int> pointDistr(1, 48);
    std::uniform_int_distribution<int> pointDistrVert(1, 18);

    while(true) {       
        sleep(700);
        if (end == true) break;
        for (int i = 0; i < enemyVec.size(); i++) {
            if (enemyVec[i].x == 1) {
                enemyVec[i].derender();
                enemyVec.erase(enemyVec.begin()+i);
            }
        }
        for (int i = 0; i < enemyVec.size(); i++) {
            enemyVec[i].derender();
            enemyVec[i].x--;
            enemyVec[i].render();  
        }
        
        if (enemyTimer == 1) {
            enemyVec.push_back(Entity(48, enemyDistr(gen), 'X'));
            enemyVec.back().render();
            enemyTimer = 0;
        }
        else enemyTimer++;
        
        if (pointTimer == 2) {
            pointVec.push_back(Entity(pointDistr(gen), pointDistrVert(gen), 'O'));
            pointVec.back().render();
            pointTimer = 0;
        }
        else pointTimer++;
        
        for (int i = 0; i < pointVec.size(); i++) {
            pointVec[i].render();
        }
        score++;
        printArena(); 
    }
}

void checkCollision() {
    while (true) {
        if (end == true) break;
        sleep(1);
        if (enemyVec.size() != 0) {
            for (Entity &e : enemyVec) {
                if (e.x == p.x && e.y == p.y) {
                    end = true;
                }
            }
        } 
        for (int i = 0; i < pointVec.size(); i++) {
            if (pointVec[i].x == p.x && pointVec[i].y == p.y) {
                fuel += 60;
                pointVec[i].derender();
                pointVec.erase(pointVec.begin()+i);
                p.render();
            }
        }
    }
}

void movePlayer(char c) {
    if (c == 'd' && p.x + 1 != 49) {
        p.derender();
        p.x++;
        p.render();
        printArena();
    }
    if (c == 'w' && p.y - 1 != 0 ) {
        p.derender();
        p.y--;
        p.render();
        printArena();
    }
    if (c == 'a' && p.x - 1 != 0) {
        p.derender();
        p.x--;
        p.render();
        printArena();
    }
    if (c == 's' && p.y + 1 != 19) {
        p.derender();
        p.y++;
        p.render();
        printArena();
    }
    if (c == 'c') {
        end = true;
        stop  = true;
    }
}

void moveLoop() {
    while (true) {
        if (end == true) break;
        sleep(100);
        fuel -= 3;
        movePlayer(direction);
        printArena();
        if (fuel <= 0) end = true;
    }
}

char deathScreen() {
    if (stop == true) return 'C';
    for (int i = 17; i < 31; i++) {
        arena[5][i] = '-';
        arena[15][i] = '-';
    }
    for (int i = 5; i < 16; i++) {
        arena[i][31] = 'l';
        arena[i][17] = 'l';
    }
    for (int i = 6; i < 15; i++) {
        for (int j = 18; j < 31; j++) {
            arena[i][j] = ' ';
        }
    }

    int offset = 20;
    std::string s = "You died!";
    for (int i = offset; i < (s.length() + offset); i++) {
        arena[7][i] = s[i - offset];
    }

    offset = 19;
    s = "Your score:";
    for (int i = offset; i < (s.length() + offset); i++) {
        arena[9][i] = s[i - offset];
    }

    s = std::to_string(score);
    offset = 0;
    int i = 0;
    for (char c : s) {
        i++;
        if (i % 2 != 0) {
            offset--;
        }
    }
    offset += 25;
    for (int i = offset; i < (s.length() + offset); i++) {
        arena[11][i] = s[i - offset];
    }

    offset = 19;
    s = "R to Retry!";
    for (int i = offset; i < (s.length() + offset); i++) {
        arena[13][i] = s[i-offset];
    }

    printArena();

    char option;
    while (true) {
        sleep(1);
        int ch = getchar();
        if (ch == 'c' || ch == 'C' || ch == 'r' || ch == 'R') {
            option = ch;
            break;
        }
    }
    return option;
}

void startGame() {   
    p.render();
    std::thread t1(gameLoop);
    std::thread t2(inputLoop);
    std::thread t3(moveLoop);
    checkCollision();
    char c = deathScreen();
    if (c == 'C' || c == 'c') return;
    if (c == 'r' || c == 'R') retry();
}

void retry() {  
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 49; j++) {
            arena[i][j] = ' ';
        }
    }
    stop = false;
    score = 0;
    fuel = 800;
    direction = 'd';
    p.derender();
    p.x = 15;
    p.y = 15;
    enemyVec.erase(enemyVec.begin(), enemyVec.end());
    pointVec.erase(pointVec.begin(), pointVec.end());
    end = false;
    startGame();
}

int main() {
    system("stty raw");
    startGame();
    system("stty cooked"); 
    return 0;
}