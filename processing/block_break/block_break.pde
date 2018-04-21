Paddle p;
Ball b;
Block bl;
ArrayList<Block> blocks = new ArrayList<Block>();




// how much height shoud we give to the stacks of blocks to break?
// should all rows be filled in? I'm thinking array to reprasent them?


void setup() {
  size(800, 600);

  int b_size  = floor(0.01 * width)/2; // provide a radius not a diameter
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
  int rows = floor( (0.55 * height)/ h ); // we'll place this many blocks in 55% of the available height
  println("rows", rows);
  println("cols", cols);

  // init our blocks in an ArrayList
  //for (int i=0; i<cols; i++) {
  //  for (int j=0; j<rows; j++) {
  //    blocks.add(new Block(i*w, j*h, w, h) );
  //  }
  //}

  // rows is fixed
  // we should vary the # cols per row which means having blokcks of vary width
  // so init blocks, outer loop of rows

  // bad implementation?
  // will never know how many cases there are as rows is dynamaic based on height!
  // so make use of default?
  // maybe have a few options in default and pick a random nuber to choose?

  for (int i=0; i<rows; i++) {
    switch (i) {
    case 0: 
      {
        // top row
        cols = 2;
        w = width/2;
        for (int j=0; j<cols; j++) {
          blocks.add(new Block(j*w, i*h, w, h));
        }
        break;
      }
    case 1: 
      { //empty row to bounce around
        break;
      }
    case 2: 
      {
        cols = 10;
        w = width / cols;
        for (int j=0; j<cols; j++) {
          blocks.add(new Block(j*w, i*h, w, h));
        }
        break;
      }
    case 3: 
      { //empty row to bounce around
        break;
      }
    case 4: 
      {
        w = floor(0.20 * width);
        cols = floor(width / w );
        for (int j=0; j<cols; j++) {
          blocks.add(new Block(j*w, i*h, w, h));
        }
        break;
      }
    case 5: 
      {
        cols = 20;
        w = width / cols;
        for (int j=0; j<cols; j++) {
          blocks.add(new Block(j*w, i*h, w, h));
        }
        break;
      }
    case 6: 
      {
        cols = 20;
        w = width / cols;
        for (int j=0; j<cols; j++) {
          int chance = (int)random(2); //just randomly decide where to place blocks
          //println(chance);
          if (chance == 1) {
            blocks.add(new Block(j*w, i*h, w, h));
          }
        }
        break;
      }
    case 7: 
      {
        cols = 10;
        w = width / cols;
        for (int j=0; j<cols; j++) {
          int chance = (int)random(2); //just randomly decide where to place blocks
          if (chance == 1) {
            blocks.add(new Block(j*w, i*h, w, h));
          }
        }
        break;
      }
    case 8: 
      { //empty row to bounce around
        break;
      }
    case 9: 
      { //empty row to bounce around
        break;
      }
      // etc
    default: 
      {
        int cols_max = 50;
        int cols_min = 1;
        cols = floor(random(cols_min, cols_max));

        w = width / cols;
        for (int j=0; j<cols; j++) {
          int chance = (int)random(2); //just randomly decide where to place blocks
          if (chance == 1) {
            blocks.add(new Block(j*w, i*h, w, h));
          }
        }
        break;
      }
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
