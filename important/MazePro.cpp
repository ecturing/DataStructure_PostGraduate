/**
 * @file MazePro.cpp
 * @author ecturing (you@domain.com)
 * @brief 迷宫问题
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

typedef struct {
  int X; //点的横坐标
  int Y; //点的纵坐标
} * MapPoint;

int Maze[5][5] = {
    {1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1}, 
    {0, 0, 1, 0, 0},
    {1, 0, 1, 1, 0}, 
    {1, 0, 0, 1, 1},
};
/**
 * @brief 左移
 * 
 * @param p 
 */
void left(MapPoint p) { --(p->Y); }

/**
  @brief 右移
 * 
 * @param p 
 */
void right(MapPoint p) { ++(p->Y); }

/**
 * @brief 上移
 * 
 * @param p 
 */
void up(MapPoint p) { --(p->X); }

/**
 * @brief 下移
 * 
 * @param p 
 */
void down(MapPoint p) { ++(p->X); }

/**
 * @brief 迷宫打印
 * 
 */
void MazePrint() {
  for (int i = 0; i < 5; i++) {
    printf("{");
    for (int j = 0; j < 5; j++) {
      printf("%d,", Maze[i][j]);
    }
    printf("}\n");
  }
}

/**
 * @brief 节点初始化
 * 
 * @param x 纵向坐标
 * @param y 横向坐标
 * @return MapPoint 
 */
MapPoint New(int x, int y) {
  MapPoint status = (MapPoint)malloc(sizeof(MapPoint));
  status->X = x;
  status->Y = y;
  return status;
}

/**
 * @brief 迷宫搜索算法
 * 
 * @param p 移动者
 */
void Search(MapPoint p) {
  stack<MapPoint> stack;//节点存储栈
  while (p->X < 5 && p->X >= 0 && p->Y >= 0 && p->Y < 5) {//撞击墙壁检测
    int rightData=Maze[(p->X)][(p->Y) + 1];
    int leftData=Maze[p->X][(p->Y) - 1] ;
    int downData=Maze[(p->X) + 1][(p->Y)] ;
    int upData=Maze[(p->X) - 1][(p->Y)] ;
    if ( rightData== 1) {//右路试探
      Maze[p->X][p->Y] = 2;
      stack.push(New(p->X, p->Y));
      right(p);
    } else if (leftData== 1) {//左路试探
      Maze[p->X][p->Y] = 2;
      stack.push(New(p->X, p->Y));
      left(p);
    } else if (downData== 1) {//下路试探
      Maze[p->X][p->Y] = 2;
      stack.push(New(p->X, p->Y));
      down(p);
    } else if (upData== 1) {//上路试探
      Maze[p->X][p->Y] = 2;
      stack.push(New(p->X, p->Y));
      up(p);
    } else {
      Maze[p->X][p->Y] = -1;//无路返回标记
      if (p->X == 4 && p->Y == 4) {//终点确认
        Maze[p->X][p->Y] = 2;
        printf("已找到路\n");
        MazePrint();
        break;
      } else if (stack.empty()) {//有路确认
        printf("无路可走\n");
        break;
      }
      p->X = stack.top()->X;
      p->Y = stack.top()->Y;
      stack.pop();//无路回退
    }
  }
}

int main() {
  MapPoint po = (MapPoint)malloc(sizeof(MapPoint));
  po->X = 0;
  po->Y = 0;
  Search(po);
  return 0;
}