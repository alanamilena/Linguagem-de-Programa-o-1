#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Astronauta {
private:
    string cpf; 
    string nome;    
    int idade;        
    bool vivo;       
    bool disponivel;  

public:
    Astronauta(string cpfrecebido, string nomerecebido, int idaderecebida) {
    cpf = cpfrecebido;      
    nome =nomerecebido;    
    idade = idaderecebida;        
    vivo = true;       
    disponivel = true;  
    }
    
    
    string getcpf() {
        return cpf;
    }
    
    string getnome() {
        return nome;
    }
    
   int getidade() {
        return idade;
    }
    
    bool getvivo() {
        return vivo;
    }
        
    bool getdisponivel() {
        return disponivel;
    }
     
    void morrer() {
    vivo = false;
    disponivel = false;
}
    
    void embarcar() {
    disponivel = false;
    }
    
    void desembarcar() {
    disponivel = true;
    }

};
  
    class Voo {
private:
    int codigo; 
    string estado;
    vector<string> cpfs;
  

public:
    Voo(int codigorecebido) {
        codigo = codigorecebido;
        estado = "planejado";
    }
    
    
    int getcodigo() {
    return codigo;
}
    
    string getestado() {
        return estado;
    }
    
    int getQuantidadeAstronautas() {
    return cpfs.size();
}

    string getCpf(int posicao) {
    return cpfs[posicao];
}
    
    bool temAstronauta(string cpf) {
    for (int i = 0; i < cpfs.size(); i++) {
        if (cpfs[i] == cpf) {
            return true;
        }
    }

    return false;
}

    void adicionarAstronauta(string cpf) {
    cpfs.push_back(cpf);
}
    
    bool removerAstronauta(string cpf) {
    for (int i = 0; i < cpfs.size(); i++) {
        if (cpfs[i] == cpf) {
            cpfs.erase(cpfs.begin() + i);
            return true;
        }
    }

    return false;
}

    void lancar() {
    estado = "em curso";
}

    void explodir() {
    estado = "finalizado com explosao";
}
    
    void finalizar() {
    estado = "finalizado com sucesso";
}

    
};
  
class Agencia {
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;
    int buscarAstronauta(string cpf) {
    for (int i = 0; i < astronautas.size(); i++) {
        if (astronautas[i].getcpf() == cpf) {
            return i;
        }
    }
    return -1;
}
    int buscarVoo(int codigo) {
    for (int i = 0; i < voos.size(); i++) {
        if (voos[i].getcodigo() == codigo) {
            return i;
        }
    }

    return -1;
}
  
public:
    void cadastrarAstronauta(string cpf, string nome, int idade) {
    int posicaoAstronauta = buscarAstronauta(cpf);

    if (posicaoAstronauta != -1) {
        cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
        return;
    }

    Astronauta novoAstronauta(cpf, nome, idade);

    astronautas.push_back(novoAstronauta);

    cout << "OK: astronauta " << cpf << " cadastrado" << endl;
}
    void cadastrarVoo(int codigo) {
    int posicaoVoo = buscarVoo(codigo);

    if (posicaoVoo != -1) {
        cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
        return;
    }

    Voo novoVoo(codigo);

    voos.push_back(novoVoo);

    cout << "OK: voo " << codigo << " cadastrado" << endl;
}

    void adicionarAstronauta(string cpf, int codigo) {
    int posicaoAstronauta = buscarAstronauta(cpf);
    int posicaoVoo = buscarVoo(codigo);

    if (posicaoAstronauta == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }

    if (posicaoVoo == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posicaoVoo].getestado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }

    if (!astronautas[posicaoAstronauta].getvivo()) {
        cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
        return;
    }

    if (voos[posicaoVoo].temAstronauta(cpf)) {
        cout << "ERRO: astronauta " << cpf
             << " ja esta no voo " << codigo << endl;
        return;
    }

    voos[posicaoVoo].adicionarAstronauta(cpf);

    cout << "OK: astronauta " << cpf
         << " adicionado ao voo " << codigo << endl;
}

    void removerAstronauta(string cpf, int codigo) {
    int posicaoAstronauta = buscarAstronauta(cpf);
    int posicaoVoo = buscarVoo(codigo);

    if (posicaoAstronauta == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }

    if (posicaoVoo == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posicaoVoo].getestado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }

    if (!voos[posicaoVoo].temAstronauta(cpf)) {
        cout << "ERRO: astronauta " << cpf
             << " nao esta no voo " << codigo << endl;
        return;
    }

    voos[posicaoVoo].removerAstronauta(cpf);

    cout << "OK: astronauta " << cpf
         << " removido do voo " << codigo << endl;
}
      
      void lancarVoo(int codigo) {
    int posicaoVoo = buscarVoo(codigo);

    if (posicaoVoo == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posicaoVoo].getestado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }

    if (voos[posicaoVoo].getQuantidadeAstronautas() == 0) {
        cout << "ERRO: voo " << codigo << " nao possui astronautas" << endl;
        return;
    }

    bool podeLancar = true;

    for (int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++) {

        string cpf = voos[posicaoVoo].getCpf(i);
        int posicaoAstronauta = buscarAstronauta(cpf);

        if (!astronautas[posicaoAstronauta].getvivo()) {
            cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
            podeLancar = false;
            break;
        }

        if (!astronautas[posicaoAstronauta].getdisponivel()) {
            cout << "ERRO: astronauta " << cpf << " esta indisponivel" << endl;
            podeLancar = false;
            break;
        }
    }

    if (podeLancar) {

        for (int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++) {

            string cpf = voos[posicaoVoo].getCpf(i);
            int posicaoAstronauta = buscarAstronauta(cpf);

            astronautas[posicaoAstronauta].embarcar();
        }

        voos[posicaoVoo].lancar();

        cout << "OK: voo " << codigo << " lancado" << endl;
    }
}
        
        void explodirVoo(int codigo) {
    int posicaoVoo = buscarVoo(codigo);

    if (posicaoVoo == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posicaoVoo].getestado() != "em curso") {
        cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
        return;
    }

    for (int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++) {

        string cpf = voos[posicaoVoo].getCpf(i);
        int posicaoAstronauta = buscarAstronauta(cpf);

        astronautas[posicaoAstronauta].morrer();
    }

    voos[posicaoVoo].explodir();

    cout << "OK: voo " << codigo << " explodiu" << endl;
}
          void finalizarVoo(int codigo) {
    int posicaoVoo = buscarVoo(codigo);

    if (posicaoVoo == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posicaoVoo].getestado() != "em curso") {
        cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
        return;
    }

    for (int i = 0; i < voos[posicaoVoo].getQuantidadeAstronautas(); i++) {

        string cpf = voos[posicaoVoo].getCpf(i);
        int posicaoAstronauta = buscarAstronauta(cpf);

        astronautas[posicaoAstronauta].desembarcar();
    }

    voos[posicaoVoo].finalizar();

    cout << "OK: voo " << codigo << " finalizado com sucesso" << endl;
}

void listarVoos() {
    cout << "LISTA DE VOOS" << endl;

    cout << "== planejado ==" << endl;

    bool encontrou = false;

    for (int i = 0; i < voos.size(); i++) {

        if (voos[i].getestado() == "planejado") {
            encontrou = true;

            cout << "Voo " << voos[i].getcodigo() << ": ";

            if (voos[i].getQuantidadeAstronautas() == 0) {
                cout << "sem astronautas";
            }
            else {
                for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {

                    string cpf = voos[i].getCpf(j);
                    int posicaoAstronauta = buscarAstronauta(cpf);

                    if (j > 0) {
                        cout << ", ";
                    }

                    cout << cpf << " "
                         << astronautas[posicaoAstronauta].getnome();
                }
            }

            cout << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }


    cout << "== em curso ==" << endl;

    encontrou = false;

    for (int i = 0; i < voos.size(); i++) {

        if (voos[i].getestado() == "em curso") {
            encontrou = true;

            cout << "Voo " << voos[i].getcodigo() << ": ";

            if (voos[i].getQuantidadeAstronautas() == 0) {
                cout << "sem astronautas";
            }
            else {
                for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {

                    string cpf = voos[i].getCpf(j);
                    int posicaoAstronauta = buscarAstronauta(cpf);

                    if (j > 0) {
                        cout << ", ";
                    }

                    cout << cpf << " "
                         << astronautas[posicaoAstronauta].getnome();
                }
            }

            cout << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }


    cout << "== finalizado com sucesso ==" << endl;

    encontrou = false;

    for (int i = 0; i < voos.size(); i++) {

        if (voos[i].getestado() == "finalizado com sucesso") {
            encontrou = true;

            cout << "Voo " << voos[i].getcodigo() << ": ";

            if (voos[i].getQuantidadeAstronautas() == 0) {
                cout << "sem astronautas";
            }
            else {
                for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {

                    string cpf = voos[i].getCpf(j);
                    int posicaoAstronauta = buscarAstronauta(cpf);

                    if (j > 0) {
                        cout << ", ";
                    }

                    cout << cpf << " "
                         << astronautas[posicaoAstronauta].getnome();
                }
            }

            cout << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }


    cout << "== finalizado com explosao ==" << endl;

    encontrou = false;

    for (int i = 0; i < voos.size(); i++) {

        if (voos[i].getestado() == "finalizado com explosao") {
            encontrou = true;

            cout << "Voo " << voos[i].getcodigo() << ": ";

            if (voos[i].getQuantidadeAstronautas() == 0) {
                cout << "sem astronautas";
            }
            else {
                for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {

                    string cpf = voos[i].getCpf(j);
                    int posicaoAstronauta = buscarAstronauta(cpf);

                    if (j > 0) {
                        cout << ", ";
                    }

                    cout << cpf << " "
                         << astronautas[posicaoAstronauta].getnome();
                }
            }

            cout << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }
}
    void listarMortos() {
    cout << "ASTRONAUTAS MORTOS" << endl;

    bool encontrou = false;

    for (int i = 0; i < astronautas.size(); i++) {

        if (!astronautas[i].getvivo()) {
            encontrou = true;

            cout << astronautas[i].getcpf() << " "
                 << astronautas[i].getnome() << " - voos:";

            bool encontrouVoo = false;

            for (int j = 0; j < voos.size(); j++) {

                if (voos[j].getestado() != "planejado" &&
                    voos[j].temAstronauta(astronautas[i].getcpf())) {

                    cout << " " << voos[j].getcodigo();
                    encontrouVoo = true;
                }
            }

            if (!encontrouVoo) {
                cout << " nenhum";
            }

            cout << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }
}
};
    


int main() {
    Agencia agencia;
    string comando;
    
    while (cin >> comando) {   // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM") {
            break;
        } else if (comando == "CADASTRAR_ASTRONAUTA") {
    string cpf, nome;
    int idade;
    cin >> cpf >> idade;
    getline(cin >> ws, nome);
    agencia.cadastrarAstronauta(cpf, nome, idade);
    
        } else if (comando == "CADASTRAR_VOO") {
    int codigo;
    cin >> codigo;
    agencia.cadastrarVoo(codigo);
        
        } else if (comando == "ADICIONAR_ASTRONAUTA") {
    string cpf;
    int codigo;
    cin >> cpf >> codigo;
    agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
    string cpf;
    int codigo;
    cin >> cpf >> codigo;
    agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
    int codigo;
    cin >> codigo;
    agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
    int codigo;
    cin >> codigo;
    agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
    int codigo;
    cin >> codigo;
    agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
    agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
    agencia.listarMortos();
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}