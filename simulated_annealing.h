template<class P,class Indiv=typename P::indiv>
struct Simulated_Annealing: Genetico<P>{
	double T;
	Simulated_Annealing(P* p):
		Genetico<P>(p,0,1,true){
		T=1;
	}
	set<Indiv>* m_poblacion(){
		return this->poblacion;
	}
	double t_aptitud(Indiv i, double aptitud_total){
		return exp((i.aptitud/aptitud_total)/T);
	}
	Indiv seleccion_de_eliminacion(){
		double backup_aptitud_total=this->aptitud_total;
		this->aptitud_total=0;
		for (auto it=m_poblacion()->begin();it!=m_poblacion()->end();it++){
			this->aptitud_total+=t_aptitud(*it,backup_aptitud_total);
		}
		auto it=m_poblacion()->begin();
		if(this->seleccion_rueda_de_ruleta(t_aptitud(*it,backup_aptitud_total))){
			this->aptitud_total=backup_aptitud_total;
			return *it;
		}
		it++;
		this->aptitud_total=backup_aptitud_total;
		return *it;
	}
	void ajustar_poblacion(){
		while(this->poblacion->size()>this->problema->tamano_de_poblacion){
			Indiv condenado=this->seleccion_de_eliminacion();
			this->aptitud_total-=condenado.aptitud;
			this->poblacion->erase(condenado);
		}
	}
	void generar_nueva_poblacion(){
		double mejorAptitud=this->obtenerMejor().aptitud;
		this->mutar_individuos();
		ajustar_poblacion();
		Indiv mejor=this->obtenerMejor();
		if(mejor.aptitud>mejorAptitud){
			T*=0.999;
		} else {
			T*=0.9999;
		}
	}
};
