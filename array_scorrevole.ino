
int inByte = 0;

char compassOsd[] = "s - - se - - e - - ne - - n - - no - - o - - so - - ";
char actualCompassOsd[] = "                    ";
char posizione [] = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 int conto = 0;
void setup()
{
Serial.begin(9600);
}


void loop()
{


if (Serial.available() > 0) {
    inByte = Serial.read();
    int x = inByte - '0';
    delay(5);
    for (int y = 0; y < 20; y++) 
      {
        int z = x + (posizione [y]);
        if (z > 51) {z = z - 51;}
        if (z < 0) {z = z + 52;}
        actualCompassOsd[y] = compassOsd[z];
      }
   
    Serial.println(actualCompassOsd);
   
    Serial.print("conto = ");
    Serial.println(conto);
    conto ++;
    Serial.read();
    Serial.read();
    Serial.read();
    }
}
