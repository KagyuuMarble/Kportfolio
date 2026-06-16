public class Pessoa
{
   private String nome;
   private String telefone;
   private Data nascimento;
   
   //construct
   public Pessoa(String nome, String telefone, Data nascimento)
   {
      this.nome = nome;
      this.telefone = telefone;
      this.nascimento = nascimento;
   }
   public Pessoa(String nome, Data nascimento)
   {
      this.nome = nome;
      this.nascimento = nascimento;
   }
   
   
   //gets and sets
   public String getNome()
   {
      return this.nome;
   }
   public String getTelefone()
   {
      return this.telefone;
   }
   public Data getNascimento()
   {
      return this.nascimento;
   }
   public void setNome(String nome)
   {
      this.nome = nome;
   }
   public void setTelefone(String telefone)
   {
      this.telefone = telefone;
   }
   public void setNascimento(Data nascimento)
   {
      this.nascimento = nascimento;
   }
   
   
   //metodo toString
   public String toString()
   {
      return "Nome:\t" + nome + "\n" +
             "Telefone:\t" + telefone + "\n" +
             "Data de nascimento:\t" + nascimento + "\n"; 
   }
   
}