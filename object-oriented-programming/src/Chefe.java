public class Chefe extends Funcionario
{
   private String cargo;
   
   //construct
   public Chefe(String nome, String telefone, Data nascimento, String registro, double salario, String cargo)
   {
      super(nome, telefone, nascimento, registro, salario);
      this.cargo = cargo;
   }
   public Chefe(String nome, Data nascimento, String registro, double salario, String cargo)
   {
      super(nome, nascimento, registro, salario);
      this.cargo = cargo;
   }
   
   //gets and sets
   public String getCargo()
   {
      return cargo;
   }
   public double getSalarioComBonificacao()
   {
      return bonificar() + super.getSalario();
   }
   public void setCargo(String cargo)
   {
      this.cargo = cargo;
   }
   
   //metodos
   public double bonificar()
   {
      return super.getSalario() * 0.2;
   }
   
   //metodo toString
   public String toString()
   {
      return super.toString() + "Cargo:\t" + cargo + "\n";
   }
}