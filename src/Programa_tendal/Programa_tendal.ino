/*  ----------------------------------------------------------------
    http://www.prometec.net/motor-28byj-48                                        Prog_4_2
    
    Moviendo un motor paso a paso 28BYJ-48 con Arduino
--------------------------------------------------------------------  
*/
#define IN1  5
#define IN2  6
#define IN3  9
#define IN4  10
#define seni 2
#define senf 11
#define LDR  

int steps_left=4095;
boolean Direction = true;
int Steps = 0;
bool FirstTime = true;

int Paso [ 8 ][ 4 ] =
    {   {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 1}
     };

     

void setup()
    {
      
      pinMode(IN1, OUTPUT); 
      pinMode(IN2, OUTPUT); 
      pinMode(IN3, OUTPUT); 
      pinMode(IN4, OUTPUT); 
      pinMode(seni, INPUT);
      pinMode(senf, INPUT);

    }
    

void loop() 
{
  if(FirstTime==true){
    if(digitalRead(senf)==1){
      stepper();
    }else{
      FirstTime=false
    }
  }
  
  if(FirstTime==false){
    if(){
      Direction=true
    }
    if(){
      Direction=false
    }
    
  }
  
  while(steps_left>0)
         {
           stepper() ;    // Avanza un paso
           steps_left-- ;  // Un paso menos
           delay (1) ;
         }
      delay(300);
      Direction=!Direction;
      steps_left=4095;
}

void stepper()            //Avanza un paso
{
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );

  SetDirection();
}

void SetDirection()
{
    if(Direction)
        Steps++;
    else 
        Steps--; 
     
    Steps = ( Steps + 7 ) % 7 ;
}
