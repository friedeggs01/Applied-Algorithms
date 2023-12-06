#include<bits/stdc++.h>

#define MAX_N 1001
#define POP_SIZE 200
#define MAX_GENERATION 300
#define CROSSOVER_RATE 0.85
#define MUTATION_RATE 0.1

using namespace std;

double dis[MAX_N][MAX_N];
int N;

class Individual {
public:    
    int chromosome[MAX_N];
    double fitness;

    Individual();
    void random_init();
    double calculate_fitness();
    void swapMutate();
    void print();
};

class Population {
public:
    vector<Individual> indivs;
    Individual best;

    void rand_init(int pop_size);
    vector<Individual> singplePointCrossover(Individual &p1, Individual &p2);
    void survival_selection(int pop_sizes);
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

Individual::Individual() {
    fitness = -1;
}

void Individual::random_init(){
    vector<int> list;
    for (int i = 0; i < N; i++){
        list.push_back(i);
    }
    shuffle(list.begin(), list.end(), rng);
    
    for (int i=0; i<N; i++) {
        this->chromosome[i] = list[i];
    }
}

double Individual::calculate_fitness() {
    double obj = dis[chromosome[N-1]][chromosome[0]];
    for (int i=1; i<N; i++) {
        obj += dis[chromosome[i-1]][chromosome[i]];
    }
    
    return 1.0 / obj;
}

void Individual::swapMutate() {
    int p1 = rand() % N;
    int p2 = rand() % N;

    while (p1 == p2) {
        p2 = rand() % N;
    }

    int tmp = chromosome[p1];
    chromosome[p1] = chromosome[p2];
    chromosome[p2] = tmp;
}

void Individual::print() {
    // cout << "obj = " << (1.0 / fitness) << ", path: ";
    for (int i=0; i<N; i++) {
        cout << (chromosome[i] +1) << " ";
    }
    cout << endl;
}
void Population::rand_init(int pop_size){
    while (indivs.size() < pop_size) {
        Individual indiv;
        indiv.random_init();
        indiv.fitness = indiv.calculate_fitness();
        
        if (best.fitness < indiv.fitness) {
            best = indiv;
        }

        indivs.push_back(indiv);
    }
}

vector<Individual> Population::singplePointCrossover(Individual &p1, Individual &p2){
    int dim = N;
    int p = rand() % dim;

    Individual o1;
    Individual o2;

    int v1[dim];
    int v2[dim];
    for (int i=0; i<dim; i++) {
        v1[i] = 0;
        v2[i] = 0;
    }

    for (int i=0; i<p; i++) {
        o1.chromosome[i] = p2.chromosome[i];
        v1[o1.chromosome[i]] = 1;

        o2.chromosome[i] = p1.chromosome[i];
        v2[o2.chromosome[i]] = 1;
    }

    int idx = 0;
    for (int i=p; i<dim; i++) {
        while (v1[p1.chromosome[idx]] != 0) {
            idx++;
        }
        o1.chromosome[i] = p1.chromosome[idx++];
        v1[o1.chromosome[i]] = 1;
    }

    idx = 0;
    for (int i=p; i<dim; i++) {
        while (v2[p2.chromosome[idx]] != 0) {
            idx++;
        }
        o2.chromosome[i] = p2.chromosome[idx++];
        v2[o2.chromosome[i]] = 1;
    }

    vector<Individual> child;
    child.push_back(o1);
    child.push_back(o2);
    return child;
}

int individual_comparator(Individual i1, Individual i2) {
    return (i1.fitness > i2.fitness);
}

void Population::survival_selection(int pop_size){
    sort(indivs.begin(), indivs.end(), individual_comparator);
    
    while (indivs.size() > pop_size) {
        indivs.pop_back();
    }
}

Population pop;

vector<Individual> reproduction(vector<Individual> mating_pool) {
    vector<Individual> offspring;

    while (offspring.size() < POP_SIZE) {
        int p1 = rand() % mating_pool.size();
        int p2 = rand() % mating_pool.size();
        while (p1 == p2) {
            p2 = rand() % mating_pool.size();
        }

        if ((double) rand() / RAND_MAX <= CROSSOVER_RATE) {
            vector<Individual> child = pop.singplePointCrossover(mating_pool[p1], mating_pool[p2]);
            offspring.insert(offspring.end(), child.begin(), child.end());
        }
    }

    for (int i=0; i<offspring.size(); i++) {
        if ((double) rand() / RAND_MAX <= MUTATION_RATE) {
            offspring[i].swapMutate();
        }

        offspring[i].fitness = offspring[i].calculate_fitness();
    }

    return offspring;
}
int id[1001];
double x[1001], y[1001];


int main() {
    freopen("4.txt", "r", stdin);
    cin >> N;
    cout << N << endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> dis[i][j];
            if(i == j) {
                dis[i][j] = INT_MAX;
            }
        }
    }
    int generation = 0;
    pop.rand_init(POP_SIZE);
    // cout << "Generation " << generation << ", best obj = " << (1.0 / pop.best.fitness) << endl;

    while (generation < MAX_GENERATION) {
        generation++;

        vector<Individual> offspring = reproduction(pop.indivs);

        pop.indivs.insert(pop.indivs.end(), offspring.begin(), offspring.end());
        pop.survival_selection(POP_SIZE);

        if (pop.best.fitness < pop.indivs[0].fitness) {
            pop.best = pop.indivs[0];
        }

        // cout << "Generation " << generation << ", best obj = " << (1.0 / pop.best.fitness) << endl;
    }

    // cout << "Best solution found: ";
    pop.best.print();
}



