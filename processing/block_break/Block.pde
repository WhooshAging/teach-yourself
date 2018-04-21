class Block {
  int w,h,x,y,r,g,b,life,alpha;
  
  Block(int xin, int yin, int win, int hin) {
    x = xin;
    y = yin;
    w = win;
    h = hin;
    
    life = 3;
    r = int(random(255));
    g = int(random(255));
    b = int(random(255));
    alpha = 255;
    
  }
  
  void update() {
    // reduces colour with each life lost
    // if life is 0 deletes block from arraylist
    switch (life) {
      case 2: {
        alpha = 155;
        break;
      }
      case 1: {
        alpha = 55;
        break;
      }
      case 0: {
       for (int i=0; i<blocks.size(); i++) {
         Block bl = blocks.get(i);
         if (x == bl.x && y == bl.y) { // Make sure we've got the right block
           blocks.remove(i); // remove it
           
         }
      }
      break;
      }
      default: {alpha = 255;}
    }
    return;
  }
  
  void render() {

    noStroke();
    fill(r,g,b,alpha);
    rect(x,y,w,h);
    
    return;
  }
  
  
  
  
}
