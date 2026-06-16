public class Principal
{
   public static void main(String args[])
   {
      int i = 0;
      //objetos
      //aluno
      Aluno aluno = new Aluno("Beltrano", "777-7777", new Data(22, 2, 2002), "20202020");
      //vetor de funcionarios:
      Funcionario v_Funcionario[] = new Funcionario[3];
      v_Funcionario[0] = new Funcionario("Ciclano", "555-5555", new Data(10, 10, 1990), "10101010", 1000);
      v_Funcionario[1] = new Chefe("Deltrano", "444-4444", new Data(9, 9, 1980), "09090909", 40000, "Chefe de departamento de computacao");
      v_Funcionario[2] = new Professor("Fulano", "333-3333", new Data(8, 8, 1980), "08080808",20000 , 16);
      
      //System output
      aluno.matricular(6);
      System.out.println(aluno);
      
      if(aluno.getMatricula() == true)
      {
      System.out.println("Carga semanal:\t" + aluno.getCargaSemanal() + "\n");
      }
     
      for(i = 0; i < 3; i++)
      {
         System.out.println(v_Funcionario[i] + "Salario Com bonificacao:\t" + v_Funcionario[i].getSalarioComBonificacao() + "\n");
      }
      ControleSalario.somaBase(v_Funcionario);
      ControleSalario.somaBonificada(v_Funcionario);
      System.out.println("Soma de salarios basicos:\t" + ControleSalario.getsomaSalariosBase());
      System.out.println("Soma de salarios bonificados:\t" + ControleSalario.getsomaSalariosBonificados());
   }

}