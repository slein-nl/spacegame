#include <iostream>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <vector>
#include <random>
#include <csignal>


char arena[20][50] = {{'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M'},
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

int score = 0;
int fuel = 2000;
int direction ='d';
void movePlayer(char c);

void printArena() {
    system("clear");
    std::cout << "Score: " + std::to_string(score) + " | Fuel: " + std::to_string(fuel);
    for (int i = 0; i < 20; i++) {
    std::cout << "\r\n";
        for (int j = 0; j < 50; j++) {
            std::cout << arena[i][j];
            std::cout << ' ';
        }
    }
    std::cout << "\r\n";
}

void sleep(int t) {
    std::this_thread::sleep_for(std::chrono::milliseconds(t));
}

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

Entity p(15, 15, '@');
std::vector<Entity> enemyVec; 
std::vector<Entity> pointVec;
bool end = false;

void inputLoop() {
    while(true) {
        sleep(1);
        direction = getchar();
        movePlayer(direction);
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
                fuel += 200;
                pointVec[i].derender();
                pointVec.erase(pointVec.begin()+i);
                p.render();
            }
        }
        if (end == true) break;
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
    }
}

void moveLoop() {
    while (true) {
        sleep(100);
        fuel -= 10;
        movePlayer(direction);
        printArena();
        if (fuel <= 0) end = true;
    }
}

int main() {
    system("stty raw");
    p.render();
    std::thread t1(gameLoop);
    std::thread t2(inputLoop);
    std::thread t3(moveLoop);
    checkCollision();
    system("stty cooked"); 
    return 0;
}

