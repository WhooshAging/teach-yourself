class Paddle {
  float x, w, h, y;
  boolean is_moving_l = false;
  boolean is_moving_r = false;

  Paddle(int win, int hin) {
    w = win;
    h = hin;
    x = width/2;
    y = height - w/2;
  }

  void update() {
    if (is_moving_l == true) {
      move('l');
    } else if (is_moving_r == true) {
      move('r');
    }

    return;
  }

  boolean checkEdges(char side) {

    if (side == 'l') {
      if (x == 0) return true;
    } else if (side == 'r') {
      if (x == width - w) return true;
    }
    return false;
  }

  void move(char side) {
    if (side == 'l') {
      boolean check = checkEdges('l');
      if (check) {
        x = 0;
        return;
      } else {
        x-= w/10;
        return;
      }
    } else if (side == 'r') {
      boolean check = checkEdges('r');
      if (check) {
        x = width - w;
        return;
      } else {
        x+= w/10;
        return;
      }
    }
    return;
  }


  void render() {
    stroke(5);
    fill(0);
    rect(x, y, w, h);

    return;
  }
}
