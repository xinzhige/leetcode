class Solution {
public:
  void cleanRoom(Robot& robot) {
    if(data[x][y] != 1){
      data[x][y]=1;
      robot.clean();
      for(int i = 0; i < 4; ++i){
        if(robot.move()){
          x += dx[dir];
          y += dy[dir];
          cleanRoom(robot);
          robot.turnLeft();
          robot.turnLeft();
          robot.move();
          robot.turnLeft();
          robot.turnLeft();
          x -= dx[dir];
          y -= dy[dir];
        }
        robot.turnLeft();
        dir = (dir + 1) % 4;
      }
    }
  }
private:
  unordered_map<int, unordered_map<int, int>> data;
  int x = 0;
  int y = 0;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int dir = 0;
};
