Paddle p;
Ball b;
Block bl;
ArrayList<Block> blocks = new ArrayList<Block>();




// how much height shoud we give to the stacks of blocks to break?
// should all rows be filled in? I'm thinking array to reprasent them?


void setup() {
  size(800, 600);

  int b_size  = floor(0.01 * width);
  int p_width = floor(0.1 * width);
  int p_height = floor(0.02 * height);

  buildBlocks();

  p = new Paddle(p_width, p_height);
  b = new Ball(b_size);
  //bl = new Block(10,10,p_width,p_height);

  return;
}



void buildBlocks() {
  // func to build an interesting layout of blocks
  // different numbers per row
  // different sizes
  // colour choices
  // 'armour' using stroke()?

  // build the blocks to break
  
  int w = floor(0.20 * width); //largest block width
  int h = floor(0.03 * height); //largest block height
  
  int cols = floor(width / w );
  int rows = floor( (0.4 * height)/ h ); // we'll place this many blocks in 55% of the available height
  println("rows", rows);
  println("cols", cols);

  // init our blocks in an ArrayList
  for (int i=0; i<cols; i++) {
    for (int j=0; j<rows; j++) {
      blocks.add(new Block(i*w, j*h, w, h) );
    }
  }

  return;
}






void keyPressed() {
  if (keyCode == LEFT) {
    p.is_moving_l = true;
  } else if (keyCode == RIGHT) {
    p.is_moving_r = true;
  }

  return;
}

void keyReleased() {
  p.is_moving_l = false;
  p.is_moving_r = false;
  return;
}





void draw() {
  // background
  noStroke();
  fill(255);
  rect(0, 0, width, height);

  p.update();
  p.render();


  b.update();
  b.render();

  //bl.render();
  for (int i = 0; i < blocks.size(); i++) {
    Block bl = blocks.get(i);

    bl.render();
  }



  return;
}
