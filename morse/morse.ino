int pinn = 11;
int del=100;
//char ww;
void setup()
{
  pinMode(pinn, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.write("Type something\n");

  while(Serial.available()){
    char ww=Serial.read();
    Serial.write(ww);
    ccase(ww);
    delay(100);
    }
    delay(500);
  






  
//  a();
//  Serial.print(" ");
//  delay(del*3);
//  b();
//  Serial.print(" ");
//  delay(del*3);
//dit();
//delay(del);
//daa();
//delay(del*2);
  
//  digitalWrite(10, HIGH);
//  delay(1000); // Wait for 1000 millisecond(s)
//  digitalWrite(10, LOW);
//  delay(1000); // Wait for 1000 millisecond(s)
}

void dit(){
  Serial.print(".");
  delay(del);
  digitalWrite(pinn,HIGH);
  delay(del);
  digitalWrite(pinn,LOW);
  delay(del);
  
}

void daa(){
  Serial.print("_");
  delay(del);
  digitalWrite(pinn,HIGH);
  delay(del*4);
  digitalWrite(pinn,LOW);
  delay(del*4); 
}

void ccase(char c){
  switch(c){
    case 'a':a();
             break;
    case 'b':b();
             break;
    case 'c':cc();
             break;
    case 'd':d();
             break;    
    case 'e':e();
             break;    
    case 'f':f();
             break;   
    case 'g':g();
             break;   
    case 'h':h();
             break;  
    case 'i':i();
             break;  
    case 'j':j();
             break;  
    case 'k':k();
             break;  
    case 'l':l();
             break; 
    case 'm':m();
             break;  
    case 'n':n();
             break; 
    case 'o':o();
             break;   
    case 'p':p();
             break;
    case 'q':q();
             break;
    case 'r':r();
             break;   
    case 's':s();
             break;   
    case 't':t();
             break;  
    case 'u':u();
             break;
    case 'v':v();
             break;
    case 'w':w();
             break;    
    case 'x':x();
             break; 
    case 'y':y();
             break;
    case 'z':z();
             break;
    }
  
  }
  
  void a(){
    dit();
    daa();
  }
  void b(){
      daa();
      dit();
      dit();
   }
   void cc(){
    daa();
    dit();
    daa();
    dit();
    }
    void d(){
      daa();
      dit();
      dit();
      }
void e(){
  dit();
  }
    void f(){
      dit();
      dit();
      daa();
      dit(); 
      }

      void g(){
        daa();
        daa();
        dit();
        }

        void h(){
          dit();    
         dit();
         dit();
         dit();
          }
void i(){
  dit();
  dit();
  }
void j(){
          dit();    
         daa();
         daa();
         daa();
  }
void k(){
  daa();
  dit();
  daa();
  }

  void l(){
    dit();
    daa();
    dit();
    dit();
    
    }
void m(){
  daa();
  daa();
  }

  void n(){
    daa();
    dit();
    }

    void o(){
      daa();
      daa();
      daa();
      }

void p(){
  dit();
  daa();
  daa()();
  dit();
  }
  
void q(){
  daa();
  daa();
  dit();
  daa();
  } 
void r(){
  dit();
  daa();
  dit();
  }
void s(){
  dit();
  dit();
  dit();
  }

void t(){
  daa();
  }
  void u(){
    dit();
    dit();
    daa();
    }
    void v(){
   dit();
    dit();
   dit();
    daa();
      
      }

      void w(){
        dit();
        daa();
        daa();
        }

        void x(){
          
          daa();
          dit();
          dit();
          daa();
          }
          void y(){
            daa();
            dit();
            daa();
            daa();
            }

            void z(){
              daa();
              daa();
              dit();
              dit();
              }
