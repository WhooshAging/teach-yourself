class Ball {
  PVector loc;
  PVector vel;
  PVector acc;
  int s; // its size


  Ball(int sin) {
    s = sin;
    loc = new PVector(width/2, height/2);
    vel = new PVector(s*0.5,s*0.5);
    acc = new PVector(0, 0);
  }

  void render() {
    ellipse(loc.x, loc.y, s*2, s*2);

    return;
  }

  void update() {
    collision();
    move();

    return;
  }

  void move() {
    vel = vel.add(acc);
    loc = loc.add(vel);

    return;
  }

  float euclDist(float x1, float x2, float y1, float y2) {
    // Reuturns Eucliden Distance between two objects
    // In this case is the distance between center of ball and center of block
    return sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
  }

  void collision() {

    // with the walls

    if (loc.x <= s || loc.x >= width - s) { //left and right

      vel.x = vel.x*(-1);
    } 
    if (loc.y <= s || loc.y >= height - s) { // top and bottom

      vel.y = vel.y*(-1);
    }

    // collision with the paddle
    
    if (loc.x + s >= p.x && loc.x + s <= p.x + p.w) { // in x bounds of paddle
      if (loc.y + s >= p.y) { // in y bounds of padde
        // we hit the paddle
        vel.mult(-1);
        //println("Hit the paddle.");
      }
    }
    
    // collision with a brick

    for (int i=0; i<blocks.size(); i++) {
      Block bl = blocks.get(i);
      // check all 4 edges of a block
      if (loc.x + s > bl.x && loc.x - s < bl.x + bl.w) { // we are in the x bounds of left and right edge
        if (loc.y + s > bl.y && loc.y - s < bl.y + bl.h) {
          //println("Hit a block.");
          vel.y = vel.y*(-1);
          bl.life -= 1;
          bl.update(); //recalculate colour based on life left. Delete from arraylist and so dont show if appropriate
          break;
        }
      }
    }






    return;
  }
}
