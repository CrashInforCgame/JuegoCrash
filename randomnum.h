// he creado esta libreria porque el glut da problemas constantemente con stdlib y necesito usar numeros aleatorios

int myRand ()  // Generate a 4 digit pseudo-random integer
{
  static int next = 3251 ; // Anything you like here - but not
                           // 0000, 0100, 2500, 3792, 7600,
                           // 0540, 2916, 5030 or 3009.
  next = ((next * next) / 100 ) % 10000 ;
  return next ;
}
 
int rand_num ( int min, int max )  // max-min must be <10000!!
{
  return myRand() % (max+1-min) + min ; 
}