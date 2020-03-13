class Solution {
public:
    int countPrimes(int n) {
        if( n <=2) 
		    return 0;
        vector<bool> primes(n) ;
        int cntPrime = 1;
        primes[2] = true;
        
        for (int i =3 ; i * i < n ;i += 2 )
        	if (!primes[i])
        		for (int j = i*i ;  j< n; j+=2*i)
        			primes[j] = true ; 
        
        for(int i = 3 ;i<n;i+=2)
		    if(!primes[i]) 
			    cntPrime++;
        return cntPrime; 
    }
};
