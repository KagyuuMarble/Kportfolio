public class Data
{

   private int dia;
   private int mes;
   private int ano;
   
   //construct
   public Data(int dia, int mes, int ano)
   {
      this.dia = dia;
      this.mes = mes;
      this.ano = ano;
   }
  
   
   //sets and gets
   public int getDia()
   {
      return dia;
   }
   public int getMes()
   {
      return mes;
   }
   public int getAno()
   {
      return ano;
   }
   public void setDia(int dia)
   {
      this.dia = dia;
   }
   public void setMes(int mes)
   {
      this.mes = mes;
   }
   public void setAno(int ano){
      this.ano = ano;
   }
  
   
   //metodo toString
   public String toString()
   {
      return dia + "/" +
             mes + "/" +
             ano;
   }  
}