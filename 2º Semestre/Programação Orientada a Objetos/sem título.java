import classes.Microondas; // Importação da classe Microondas

import java.util.InputMismatchException;// Importação da exeception
import java.util.Scanner; // Importação da biblioteca de leitura das váriaveis

public class Objeto {
	/**
	 * @author Luiz Zairo Bastos Viana, Victor Manoel Pinheiro Coutinho, Francisco Eduardo Vito Sena Alves
	 * @version 20/02/2021
	 */

	public static void main(String[] args) {
		Scanner num = new Scanner(System.in);
		Microondas m = new Microondas();
		int opc,tempo,potencia;
		try {
			do {
				try {
					System.out.println("\nMENU");
					System.out.println("1 - Ligar");
					System.out.println("2 - Ligar com tempo definido");
					System.out.println("3 - Ajustar Potência");
					System.out.println("4 - Menu pratos");
					System.out.println("5 - Sair");
					System.out.print("Opção: ");
					opc= num.nextInt();
					switch (opc){
						case 1:
							System.out.println("\nSelecionado: 1 - Ligar");
							m.liga();
						break;
						case 2:
							System.out.println("\nSelecionado: 2 - Ligar com tempo definido");
							System.out.print("Definir tempo de utilização: ");
							tempo = num.nextInt();
							m.ligarTempo(tempo);
						break;
						case 3:
							try {
								System.out.println("\nSelecionado: 3 - Ajustar Potência");
								System.out.print("Valor da potência: ");
								potencia = num.nextInt();
								m.setPotencia(potencia);
							}catch(InputMismatchException e) {
								System.out.println(e.getMessage());
							}
							
						break;
						case 4:
							System.out.println("\nSelecionado: 4 - Menu pratos");
						break;
						case 5:
							System.out.println("\nSelecionado: 5 - Sair");
							System.out.println("Saindo!");
						break;
						default:
							System.out.println("Selecione uma opção entre 1 - 5");
						break;
					}
				}catch(InputMismatchException e) {
					System.out.println("Dado inválido!Aceito apenas números inteiros, dentro do intervalo de 1 - 5.");
					clearBuffer(num);
					opc=0;
				}
				
			
			}while(opc!=5);
		}catch (InputMismatchException e){
			System.out.println("Dado inválido! Aceito apenas números inteiros.");
			return;
		}
	}
	private static void clearBuffer(Scanner scanner) {
        if (scanner.hasNextLine()) {
            scanner.nextLine();
        }
    }
}
