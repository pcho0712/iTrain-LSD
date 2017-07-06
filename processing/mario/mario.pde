





static int u = 5;//unit
Player mario;
Player luigi;


void setup() {
  //size(8*10,24*10); //equals multiplication of unit
  size(960, 40);//240 * 8
  frameRate(20);


  mario = new Player();
  luigi = new Player(color(0, 255, 0));
}



void draw() {
  background(0);

  mario.update();
  mario.display();
  luigi.update();
  luigi.display();
}


void keyPressed() {

  if (key=='d') luigi.moveRight();
  if (key=='a') luigi.moveLeft();
  if (key=='w') luigi.moveUp();
  if (key=='s') luigi.moveDown();
  if (key=='x') luigi.jump();


  if (key==CODED) {
    if (keyCode==RIGHT) mario.moveRight();
    if (keyCode==LEFT) mario.moveLeft();
    if (keyCode==UP) mario.moveUp();
    if (keyCode==DOWN) mario.moveDown();
    //if (keyCode==RETURN) mario.jump();
  }
    if (key==' ') mario.jump();

}