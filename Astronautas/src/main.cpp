#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

    Astronauta(string cpfrecebido, string nomerecebido, int idaderecebida,
               bool vivorecebido, bool disponivelrecebido) {
    cpf = cpfrecebido;
    nome = nomerecebido;
    idade = idaderecebida;
    vivo = vivorecebido;
    disponivel = disponivelrecebido;
    }
    
    
    string getcpf() const {
        return cpf;
    }
    
    string getnome() const {
        return nome;
    }
    
   int getidade() const {
        return idade;
    }
    
    bool getvivo() const {
        return vivo;
    }
        
    bool getdisponivel() const {
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

    Voo(int codigorecebido, string estadorecebido) {
        codigo = codigorecebido;
        estado = estadorecebido;
    }
    
    
    int getcodigo() const {
    return codigo;
}
    
    string getestado() const {
        return estado;
    }
    
    int getQuantidadeAstronautas() const {
    return cpfs.size();
}

    string getCpf(int posicao) const {
    return cpfs[posicao];
}
    
    bool temAstronauta(string cpf) const {
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

    void listarAstronautas() {
    cout << "LISTA DE ASTRONAUTAS" << endl;

    cout << "== disponiveis ==" << endl;

    bool encontrou = false;

    for (int i = 0; i < astronautas.size(); i++) {

        if (!astronautas[i].getvivo()) {
            continue;
        }

        bool emVoo = false;

        for (int j = 0; j < voos.size(); j++) {

            if (voos[j].getestado() == "em curso" &&
                voos[j].temAstronauta(astronautas[i].getcpf())) {
                emVoo = true;
                break;
            }
        }

        if (!emVoo) {
            encontrou = true;

            cout << astronautas[i].getcpf() << " "
                 << astronautas[i].getnome() << " ("
                 << astronautas[i].getidade() << " anos)" << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }


    cout << "== em voo ==" << endl;

    encontrou = false;

    for (int i = 0; i < astronautas.size(); i++) {

        if (!astronautas[i].getvivo()) {
            continue;
        }

        for (int j = 0; j < voos.size(); j++) {

            if (voos[j].getestado() == "em curso" &&
                voos[j].temAstronauta(astronautas[i].getcpf())) {

                encontrou = true;

                cout << astronautas[i].getcpf() << " "
                     << astronautas[i].getnome() << " ("
                     << astronautas[i].getidade() << " anos)"
                     << " - voo " << voos[j].getcodigo() << endl;

                break;
            }
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }


    cout << "== mortos ==" << endl;

    encontrou = false;

    for (int i = 0; i < astronautas.size(); i++) {

        if (!astronautas[i].getvivo()) {
            encontrou = true;

            cout << astronautas[i].getcpf() << " "
                 << astronautas[i].getnome() << " ("
                 << astronautas[i].getidade() << " anos)" << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum)" << endl;
    }
}

    void historico(string cpf) {
    int posicaoAstronauta = buscarAstronauta(cpf);

    if (posicaoAstronauta == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }

    cout << "HISTORICO DE " << cpf << " "
         << astronautas[posicaoAstronauta].getnome() << endl;

    bool encontrou = false;

    for (int j = 0; j < voos.size(); j++) {

        if (voos[j].getestado() != "planejado" &&
            voos[j].temAstronauta(cpf)) {

            encontrou = true;

            cout << "voo " << voos[j].getcodigo() << ": "
                 << voos[j].getestado() << endl;
        }
    }

    if (!encontrou) {
        cout << "(nenhum voo)" << endl;
    }
}

    void salvarDados(string nomeArquivo) {
    ofstream saida(nomeArquivo);

    if (!saida) {
        cout << "ERRO: nao foi possivel salvar em "
             << nomeArquivo << endl;
        return;
    }

    saida << "astronautas" << endl;
    saida << astronautas.size() << endl;

    for (int i = 0; i < astronautas.size(); i++) {
        saida << astronautas[i].getcpf() << endl;
        saida << astronautas[i].getnome() << endl;
        saida << astronautas[i].getidade() << endl;
        saida << astronautas[i].getvivo() << endl;
        saida << astronautas[i].getdisponivel() << endl;
    }

    saida << "voos" << endl;
    saida << voos.size() << endl;

    for (int i = 0; i < voos.size(); i++) {
        saida << voos[i].getcodigo() << endl;
        saida << voos[i].getestado() << endl;
        saida << voos[i].getQuantidadeAstronautas() << endl;

        for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {
            saida << voos[i].getCpf(j) << endl;
        }
    }

    saida.close();

    cout << "OK: dados salvos em " << nomeArquivo << endl;
}

    void carregarDados(string nomeArquivo) {
    ifstream entrada(nomeArquivo);

    if (!entrada) {
        cout << "ERRO: nao foi possivel carregar de "
             << nomeArquivo << endl;
        return;
    }

    vector<Astronauta> astronautasTemporarios;
    vector<Voo> voosTemporarios;

    string marcador;
    int quantidade;
    entrada >> marcador;
    entrada >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        string cpf, nome;
        int idade, vivo, disponivel;

        entrada >> cpf;
        getline(entrada >> ws, nome);
        entrada >> idade >> vivo >> disponivel;

        Astronauta astronautaCarregado(cpf, nome, idade,
                                       vivo == 1, disponivel == 1);

        astronautasTemporarios.push_back(astronautaCarregado);
    }

    entrada >> marcador;
    entrada >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        int codigo, quantCpf;
        string estado, cpf;

        entrada >> codigo;
        getline(entrada >> ws, estado);
        entrada >> quantCpf;

        Voo vooCarregado(codigo, estado);

        for (int j = 0; j < quantCpf; j++) {
            entrada >> cpf;
            vooCarregado.adicionarAstronauta(cpf);
        }

        voosTemporarios.push_back(vooCarregado);
    }

    entrada.close();

    astronautas = astronautasTemporarios;
    voos = voosTemporarios;

    cout << "OK: dados carregados de " << nomeArquivo << endl;
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
        } else if (comando == "LISTAR_ASTRONAUTAS") {
    agencia.listarAstronautas();
        } else if (comando == "HISTORICO") {
    string cpf;
    cin >> cpf;
    agencia.historico(cpf);
        } else if (comando == "SALVAR") {
    string nomeArquivo;
    cin >> nomeArquivo;
    agencia.salvarDados(nomeArquivo);
        } else if (comando == "CARREGAR") {
    string nomeArquivo;
    cin >> nomeArquivo;
    agencia.carregarDados(nomeArquivo);
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}