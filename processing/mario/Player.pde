class Player {

  PVector pos;
  int size;
  int debCol;

  Player() {
    pos=new PVector(0, 6);
    size =2;
    debCol =color(255, 0, 0);
  }
  Player(color col) {
    this();

    debCol = col;
  }



  void moveRight() {
    pos.x++;
  }
  void moveLeft() {
    pos.x--;
  }
  void moveUp(){
    pos.y--;
  }
  void moveDown(){
   pos.y++; 
  }



  /*jumping*/

  int frameJumpDuration = 20;
  int frameJumpStart=-10000;//minus-inf

  void jump() {
    frameJumpStart = frameCount;
  }
  boolean isJump() {
    if (frameCount - frameJumpStart < frameJumpDuration ) return true;
    else return false;
  }
  void moveWhileJump(int count) {
    if (count==0) pos.y--;
    if (count==1) pos.y--;
    if (count==2) pos.y--;
    if (count==4) pos.y--;
    if (count==7) pos.y--;
    //    if (count==8) pos.y++;
    if (count==10) pos.y++;
    if (count==12) pos.y++;
    if (count==13) pos.y++;
    if (count==14) pos.y++;
  }


  void update() {
    if (isJump()) moveWhileJump(frameCount - frameJumpStart );
  }

  void display() {
    ellipseMode(CENTER);  

    pushMatrix();  
    translate(pos.x*u, pos.y*u);

    noStroke();
    fill(debCol);
    ellipse(0, 0, u*size, u*size);

    popMatrix();
  }
}  