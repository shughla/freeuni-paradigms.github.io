class jedimaster {    
	public:         
		int luke(jedimaster *macewindu, jedimaster obiwan);
	       int& anakin(short *padme, jedimaster& leia);
	    
	private:      
	       short council[4];
	       short *yoda;
};

int jedimaster::luke(jedimaster *macewindu, jedimaster obiwan) {    
	obiwan.yoda += macewindu->council[40];
	return obiwan.anakin((short *) &obiwan, *this);
}
