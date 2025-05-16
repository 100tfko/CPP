#ifndef HARL_HPP
# define HARL_HPP

//#pragma	once  seria lo mismo que poner los defines, se podr'ian quitar
# include <iostream>
# include <string>

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif