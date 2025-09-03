/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:50:15 by lcuevas-          #+#    #+#             */
/*   Updated: 2025/07/02 10:50:17 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm ("Shrubbery", "DefaultTarget", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm ("Shrubbery", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) 
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw(ShrubberyCreationForm::NotSignedException());
	else if (getGradeToExecute() < executor.getGrade())
		throw(ShrubberyCreationForm::GradeTooLowException());
	else
	{
		std::cout << "Some nice trees has been planted in " << this->getTarget() << "_srubbery" << std::endl;
		std::ofstream	file((this->getTarget() + "_srubbery").c_str());
  
        if (!file)
        {
            std::cerr << "Error opening file " << std::endl;
            return;
        }

        file <<
			"              _{\\ _{\\{\\/}/}/}__" << std::endl <<
			"             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl <<
			"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl <<
			"         {\\{/(/}\\}{/{/\\}\\}{/)\\{/\\" "\\} /\\}" << std::endl <<
			"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl <<
			"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl <<
			"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl <<
			"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl <<
			"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl <<
			"      {\\{\\/}(_){\\{\\{\\/}/}(_) {\\/}{\\/}/})/}" << std::endl <<
			"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl <<
			"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl <<
			"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl <<
			"         {/(/{\\{/{\\{\\/}(_) {\\/}/}\\}/}(\\}" << std::endl <<
			"          (_) {/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl <<
			"            {/{/{\\{\\/}{/{\\{\\{(_) /}" << std::endl <<
			"             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl <<
			"              {){/ {\\/}{\\/} \\}\\}" << std::endl <<
			"              (_)  \\.-'.-/" << std::endl <<
			"          __...--- |'-.-'| --...__" << std::endl <<
			"   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl <<
			" -\"    ' .  . '    |.'-._| '  . .  '     " << std::endl <<
			" .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl <<
			"          ' ..     |'-_.-| " << std::endl <<
			"  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl <<
			"              .'   |'- .-|   '." << std::endl <<
			"  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl <<
			"   .-' '        '-._______.-'     '  ." << std::endl <<
			"        .      ~," << std::endl <<
			"    .       .   |\\   .    ' '-." << std::endl <<
			"    ___________/  \\____________" << std::endl <<
			"   /  Why is it, when you want \\" << std::endl <<
			"  |  something, it is so damn   |" << std::endl <<
			"  |    much work to get it?     |" << std::endl <<
			"   \\___________________________/" << std::endl;
	    file.close();
    }
}




