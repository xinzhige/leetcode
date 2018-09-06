class SnakeGame {
public:
  SnakeGame(int w, int h, vector<pair<int, int>> f) : width(w),
                                                      height(h),
                                                      food(f),
                                                      score(0),
                                                      snake({{0, 0}}) {}

  int move(string direction) {
    auto head = snake.front();
    auto tail = snake.back();
    snake.pop_back();
    if (direction == "U") {
      head.first -= 1;
    } else if (direction == "L") {
      head.second -= 1;
    } else if (direction == "R") {
      head.second += 1;
    } else if (direction == "D") {
      head.first += 1;
    }
    if (count(snake.begin(), snake.end(), head) > 0 || head.first < 0 ||
        head.first >= height || head.second < 0 || head.second >= width) {
        return -1;
    }
    snake.insert(snake.begin(), head);
    if (!food.empty() && head == food.front()) {
        food.erase(food.begin());
        snake.push_back(tail);
        score += 1;
    }
    return score;
  }

private:
  int width, height, score;
  vector<pair<int, int>> food;
  list<pair<int, int>> snake;
};
