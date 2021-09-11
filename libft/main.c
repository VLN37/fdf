/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:05:07 by jofelipe          #+#    #+#             */
/*   Updated: 2021/08/13 11:39:38 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	isalphasupport(void)
{
	for (int i = 65; i <= 90; i++)
	{
		if(!(ft_isalpha(i)))
			return(0);
	}
	for (int i = 97; i <= 121; i++)
	{
		if(!(ft_isalpha(i)))
			return(0);
	}
	return (1);
}

int	isdigitsupport(void)
{
	for (int i = 0; i <= 9; i++)
	{
		if (!ft_isdigit(i))
			return (0);
	}
	return (1);
}

int	isalnumsupport(void)
{
	for (int i = '0'; i <= '9'; i++)
	{
		if (!ft_isalnum(i))
			return (0);
	}
	for (int i = 65; i <= 90; i++)
	{
		if(!(ft_isalnum(i)))
			return(0);
	}
	for (int i = 97; i <= 121; i++)
	{
		if(!(ft_isalnum(i)))
			return(0);
	}
	return (1);
}

int	isasciisupport(void)
{
	for (int i = 0; i <= 127; i++)
	{
		if (!ft_isascii(i))
			return (0);
	}
	return (1);
}

int	isprintsupport(void)
{
	for (int i = 32; i < 127; i++)
	{
		if(!ft_isprint(i))
			return (0);
	}
	return (1);
}

int	touppersupport(void)
{
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (ft_toupper(i) != i - 32)
			return (0);
	}
	return (1);
}

int	tolowersupport(void)
{
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (ft_tolower(i) != i + 32)
			return (0);
	}
	return (1);
}

int splitsupport(char **split)
{
	int i = 0;
	if (strcmp(split[0], "let's"))
		return (1);
	if (strcmp(split[1], "split"))
		return (1);
	if (strcmp(split[2], "this"))
		return (1);
	if (strcmp(split[3], "for"))
		return (1);
	if (strcmp(split[4], "glory"))
		return (1);
	if (strcmp(split[5], "!"))
		return (1);
	return (0);
}

char toupperr(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return(c);
}

void toupperriter(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

static void del(void *content)
{
	if (content)
		content = NULL;
}

// void lstprint(t_list *head)
// {
// 	while(head)
// 	{
// 		if (head->content != NULL)
// 			printf("%s\n", (char *)head->content);
// 		head = head->next;
// 	}
// }

// int	lstsupport(t_list *begin, char **strs)
// {
// 	int	i;
// 	i = 0;
// 	while(begin)
// 	{
// 		if(strcmp((char *)begin->content, strs[i]))
// 			return(1);
// 		i++;
// 		begin = begin->next;
// 	}
// 	return (0);
// }

int	main(void)
{

	int i = 0;
	//ft_isalpha
	if (ft_isalpha(EOF))
		printf("[KO] Isalpha returns 1 on EOF\n");
	else if(ft_isalpha('\0'))
		printf("[KO] Isalpha returns 1 on NULL\n");
	else if(ft_isalpha('@'))
		printf("[KO] Isalpha returned 1 on @\n");
	else if(ft_isalpha('['))
		printf("[KO] Isalpha returned 1 on [\n");
	else if(ft_isalpha(96))
		printf("[KO] Isalpha returned 1 on 96\n");
	else if(ft_isalpha(123))
		printf("[KO] Isalpha returned 1 on 123\n");
	else if(!isalphasupport())
		printf("[KO] isalpha returned 0 on alphabetical\n");
	else
		printf("[OK] ft_isalpha\n");

	//ft_isdigit
	if (isdigitsupport())
		printf("[KO] digit returns 0\n");
	else if(ft_isdigit(11))
		printf("[KO] is digit returned 1 on 11\n");
	else if(ft_isdigit(0))
		printf("[KO] is digit returned 1 on 0\n");
	else
		printf("[OK] ft_isdigit\n");

	//ft_isalnum
	if (ft_isalnum(EOF))
		printf("[KO] Isalpha returns 1 on EOF\n");
	else if(ft_isalnum('\0'))
		printf("[KO] Isalpha returns 1 on NULL\n");
	else if(ft_isalnum('@'))
		printf("[KO] Isalpha returned 1 on @\n");
	else if(ft_isalnum('['))
		printf("[KO] Isalpha returned 1 on [\n");
	else if(ft_isalnum(96))
		printf("[KO] Isalpha returned 1 on 96\n");
	else if(ft_isalnum(123))
		printf("[KO] Isalpha returned 1 on 123\n");
	else if(ft_isalnum(11))
		printf("[KO] is digit returned 1\n");
	else if(ft_isalnum(0))
		printf("[KO] is digit returned 1\n");
	else if(!isalnumsupport())
		printf("[KO] alnum returns 0 on alphanumeric\n");
	else
		printf("[OK] ft_isalnum\n");

	//isascii
	if (ft_isascii(-1))
		printf("[KO] isascii returns 1 on negative\n");
	else if (ft_isascii(128))
		printf("[KO] isascii returns 1 over 127\n");
	else if (!isasciisupport())
		printf("[KO] isascii returns 0 in ascii range\n");
	else
		printf("[OK] ft_isascii\n");

	//isprint
	if (ft_isprint(19))
		printf("[KO] isprint returns 1 on 19\n");
	else if (ft_isprint(127))
		printf("[KO] isprint returns 1 on 127\n");
	else if (!isprintsupport())
		printf("[KO] isprint returns 0 on printable characters\n");
	else
		printf("[OK] ft_isprint\n");

	//strlen
	if (ft_strlen("Hello World!") != 12)
		printf("incorrect return on strlen's test 1\n");
	else if (ft_strlen("") != 0)
		printf("incorrect return on empty string\n");
	else
		printf("[OK] ft_strlen\n");

	//memset
	char str1[] = "";
	char str2[] = "";
	char str3[] = "123123123123";
	char str4[] = "123123123123";
	char str5[] = "justtestingthisfornopurposeatall";
	char str6[] = "justtestingthisfornopurposeatall";
	memset(str1, '$', 1);
	ft_memset(str2, '$', 1);
	memset(str3, '$', 9);
	ft_memset(str4, '$', 9);
	memset(str5, '$', 15);
	ft_memset(str6, '$', 15);
	if (strncmp(str1, str2, 1))
		printf("[KO] memset fails on test 1\n");
	else if (strncmp(str3, str4, 9))
		printf("[KO] memset fails on test 2\n");
	else if (strncmp(str5, str6, 15))
		printf("[KO] memset fails on test 3\n");
	else
		printf("[OK] ft_memset\n");

	//bzero
	memset(str1, 0, 1);
	ft_bzero(str2, 1);
	memset(str3, 0, 9);
	ft_bzero(str4, 9);
	memset(str5, 0, 15);
	ft_bzero(str6, 15);
	if (strncmp(str1, str2, 1))
		printf("[KO] bzero fails on test 1\n");
	else if (strncmp(str3, str4, 9))
		printf("[KO] bzero fails on test 2\n");
	else if (strncmp(str5, str6, 15))
		printf("[KO] bzero fails on test 3\n");
	else
		printf("[OK] ft_bzero\n");

	//memcpy
	int array1[] = {1, 2, 3};
	int array2[] = {4, 5, 6};
	int array3[] = {7, 8, 9};
	memcpy(array2, array1, 12);
	ft_memcpy(array3, array1, 12);
	if (memcmp(array2, array3, 12))
		printf("[KO] memcpy\n");
	else
		printf("[OK] ft_memcpy\n");

	//memmove
	char move1[] = "abcd";
	char move2[] = "cdba";
	char move3[] = "cdba";

	memmove(&move2[2], move1, 2);
	ft_memmove(&move3[2], move1, 2);
	if(strcmp(move2, move3))
		printf("[KO] strings are not the same\n");
	else
		printf("[OK] ft_memmove\n");

	//strlcpy
	char lcpy1[] = "ninjaninja";
	char lcpy2[] = "imnotninja";
	char lcpy3[] = "ninjaninja";
	ft_strlcpy(lcpy2, lcpy1, 11);
	if (strcmp(lcpy2, lcpy3))
		printf("[KO] strlcpy strings are not the same\n");
	else
		printf("[OK] ft_strlcpy\n");

	//strlcat
	char lcat1[50] = "these strings";
	char lcat2[] = " are together!";
	char lcat3[] = "these strings are together!";
	ft_strlcat(lcat1, lcat2, 30);
	if (ft_strncmp(lcat1, lcat3, 30))
		printf("[KO] strlcat strings are not the same\n");
	else
		printf("[OK] ft_strlcat\n");

	//toupper
	if (ft_toupper(123) != 123)
		printf("[KO] toupper modifies non-alphabetic chars\n");
	else if (ft_toupper(75) != 75)
		printf("[KO] toupper modifies uppercase chars\n");
	else if (ft_toupper(96) != 96)
		printf("[KO] toupper modifies non-alphabetic chars\n");
	else if (!touppersupport())
		printf("[KO] toupper does not uppercase all lowercase characters\n");
	else
		printf("[OK] ft_toupper\n");

	//tolower
	if (ft_tolower(64) != 64)
		printf("[KO] tolower modifies non-alphabetic chars\n");
	else if (ft_tolower(110) != 110)
		printf("[KO] tolower modifies lowercase chars\n");
	else if (ft_tolower(91) != 91)
		printf("[KO] tolower modifies non-alphabetic chars\n");
	else if (!tolowersupport())
		printf("[[KO] tolower does not lowercase all uppercase characters\n");
	else
		printf("[OK] ft_tolower\n");

	//strchr
	char *teste2 = "abccdefg";
	if (ft_strchr(teste2, 'c') != &teste2[2])
		printf("[KO] strchr returns different addresses\n");
	else if (ft_strchr(teste2, 'h') != 0)
		printf("[KO] strchr returns does not return NULL\n");
	else
		printf("[OK] ft_strchr\n");

	//strrchr
	if (ft_strrchr(teste2, 'c') != &teste2[3])
		printf("[KO] strchr returns different addresses\n");
	else if (ft_strrchr(teste2, 'h') != 0)
		printf("[KO] strchr returns does not return NULL\n");
	else
		printf("[OK] ft_strchr\n");

	//strncmp
	if (ft_strncmp("A", "B", 2) >= 0)
		printf("[KO] strncmp fail on test 1\n");
	else if (ft_strncmp("A", "", 1) <= 0)
		printf("[KO] strncmp fail on test 2\n");
	else if (ft_strncmp("A", "AB", 2) >= 0)
		printf("[KO] strncmp fail on test 3\n");
	else if (ft_strncmp("Norm", "Norm", 5) != 0)
		printf("[KO] strncmp fail on test 4\n");
	else
		printf("[OK] ft_strncmp\n");

	//memchr
	char str7[] = "hello";
	if ((char *)memchr(str7, 'o', 5) != &str7[4])
		printf("[KO] memchr fails test 1\n");
	else if((char *)memchr(str7, 'p', 5))
		printf("[KO] memchr does not return NULL\n");
	else
		printf("[OK] ft_memchr\n");

	//memcmp
	char str8[] = "hello";
	char str9[] = "hellZ";
	if (memcmp(str8, str9, 4) != ft_memcmp(str8, str9, 4))
		printf("[KO] memcmp does not return 0 as expected\n");
	else if (memcmp(str8, str9, 5) < 0)
		printf("[KO] memcmp does not return a difference as expected\n");
	else
		printf("[OK] ft_memcmp\n");

	//strnstr
	char teste1[] = "i like what? Bananas and strawberries";
	if (ft_strnstr(teste1, "Bananas", 25) != &teste1[13])
		printf("[KO] strnstr fail on test 1\n");
	if (ft_strnstr(teste1, "Bananas", 10) != 0)
		printf("[KO] strnstr does not return null\n");
	else
		printf("[OK] ft_strnstr\n");

	//atoi
	if (ft_atoi("      -2147483648") != -2147483648)
		printf("[KO] atoi fails MIN_INT\n");
	else if (ft_atoi("      +2147483647") != 2147483647)
		printf("[KO] atoi fails MAX_INT\n");
	else if (ft_atoi("    a  -++-+----2147483648") != 0)
		printf("[KO] atoi fails test 3\n");
	else if (ft_atoi("      -++-+s----1337") != 0)
		printf("[KO] atoi fails test 4\n");
	else if (ft_atoi("   -1337s1337") != -1337)
		printf("[KO] atoi fails test 5\n");
	else if (ft_atoi("-70703") != -70703)
		printf("[KO] atoi fails test 6\n");
	else if (ft_atoi("1231a1") != 1231)
		printf("[KO] atoi fails test 7\n");
	else
		printf("[OK] ft_atoi\n");

	//calloc
	char *ptr = ft_calloc(4, 5);
	if (memcmp(ptr, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20))
		printf("[KO] ft_calloc\n");
	else
		printf("[OK] ft_calloc\n");
	free(ptr);

	//strdup
	char *str10 = "string to be duped";
	char *str11 = ft_strdup(str10);
	if(&str10 == &str11)
		printf("[KO] ft_strdup addresses are the same\n");
	else if (memcmp(str10, str11, ft_strlen(str3) + 1))
		printf("[KO] ft_strdup contents are not the same\n");
	else
		printf("[OK] ft_strdup\n");

	printf ("\n----- Part 2-----\n");

	//substr
	char substr1[] = "this is not cut and this is cut";
	char *substr2 = ft_substr(substr1, 0, 15);
	if (strcmp(substr2, "this is not cut"))
		printf("[KO] substr not corrrect\n");
	else
		printf("[OK] ft_substr\n");

	//strjoin
	char strjoin1[] = "Don't panic";
	char strjoin2[] = " plz";
	char *strjoin3 = ft_strjoin(strjoin1, strjoin2);
	if (strcmp(strjoin3, "Don't panic plz"))
		printf("[KO] strjoin strings are not concatenated\n");
	else
		printf("[OK] ft_strjoin\n");

	//strtrim
	char *strtrim1 = "   Don't Panic!   ";
	char *strtrim2 = "1232Don't Panic!";
	char *strtrim3 = "Don't Panic123221";
	char *strtrim4 = "Don't Panic!";
	strtrim1 = ft_strtrim("   Don't Panic!   ", " ");
	strtrim2 = ft_strtrim("1232Don't Panic!", "123");
	strtrim3 = ft_strtrim("Don't Panic!123221", "123");
	if (strcmp(strtrim1, strtrim4))
		printf("[KO] strtrim fails on test 1\n");
	else if (strcmp(strtrim2, strtrim4))
		printf("[KO] strtrim fails on test 2\n");
	else if (strcmp(strtrim3, strtrim4))
		printf("[KO] strtrim fails on test 3\n");
	else
		printf("[OK] ft_strtrim\n");
	free(strtrim1);
	free(strtrim2);
	free(strtrim3);

	//split
	char **split2;
	char **split3;
	split2 = ft_split("  let's split this for   glory !     ", ' ');
	split3 = ft_split( "1-2-3-4-5-6-7-8--8-8--8-4------4--4", '-');
	i = -1;
	while (split3[++i])
		printf("%s\n", split3[i]);
	if (splitsupport(split2))
		printf("[KO] split array is not as expected\n");
	else
		printf("[OK] ft_split\n");
	i = 0;
	while(split2[i])
		free(split2[i++]);
	i = 0;
	while(split3[i])
		free(split3[i++]);
	i = 0;


	//itoa
	if(strncmp(ft_itoa(0), "0", 2) != 0)
		printf("[KO] itoa fails on 0\n");
	else if (strncmp(ft_itoa(10), "10", 3) != 0)
		printf("[KO] itoa fails on test 1\n");
	else if (strncmp(ft_itoa(-10), "-10", 4) != 0)
		printf("[KO] itoa fails on negative\n");
	else if (strncmp(ft_itoa(12354), "12354", 7) != 0)
		printf("[KO] itoa\n");
	else if (strncmp(ft_itoa(2147483647), "2147483647", 11) != 0)
		printf("[KO] itoa fails on INT_MAX\n");
	else if (strncmp(ft_itoa(-2147483648), "-2147483648", 12) != 0)
		printf("[KO] itoa fails on INT_MIN\n");
	else
		printf("[OK] ft_itoa\n");

	//strmapi
	char *strmapi1;
	strmapi1 = ft_strmapi("capitalizethis", &toupperr);
	if (strcmp(strmapi1, "CAPITALIZETHIS"))
		printf("[KO] strmapi does not capitalize your string\n");
	else
		printf("[OK] ft_strmapi\n");
	free(strmapi1);

	//striteri
	char striteri1[] = "capitalizethis";
	ft_striteri(striteri1, &toupperriter);
	if (strcmp(striteri1, "CAPITALIZETHIS"))
		printf("[KO] striteri does not capitalize the string\n");
	else
		printf("[OK] ft_striteri\n");

	//putchar_fd
	int	fd;
	char charfd[5];

	fd = open("ghost", O_RDWR | O_CREAT);
	ft_putchar_fd('a', fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, charfd, 2);
	close(fd);
	if (strncmp("a", charfd, 1))
		printf("[KO] putchar_fd, content was not written\n");
	else
		printf("[OK] ft_putchar_fd\n");
	unlink("./ghost");

	// putstr_fd
	char strfd[50];

	fd = open("ghost", O_RDWR | O_CREAT);
	ft_putstr_fd("don't panic!", fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, strfd, 12);
	close(fd);
	if(strncmp("don't panic!", strfd, 12))
		printf("[KO] str_fd does not write on file\n");
	else
		printf("[OK] ft_putstr_fd\n");
	unlink("./ghost");

	//putendl_fd
	char endlfd[50];

	fd = open("ghost", O_RDWR | O_CREAT);
	ft_putendl_fd("don't panic!", fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, endlfd, 13);
	if (strncmp("don't panic!\n", endlfd, 13))
		printf("[KO] putendl_fd does not write correctly\n");
	else
		printf("[OK] ft_putendl_fd\n");
	unlink("./ghost");

	//putnbr_fd
	char putnbrfd1[50];
	char putnbrfd2[50];
	char putnbrfd3[50];
	char putnbrfd4[50];
	char putnbrfd5[50];

	fd = open("ghost", O_RDWR | O_CREAT);
	ft_putnbr_fd(-2147483648, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, putnbrfd1, 11);
	unlink("./ghost");

	fd = open("ghost", O_RDWR | O_CREAT);
	ft_putnbr_fd(2147483647, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, putnbrfd2, 11);
	unlink("./ghost");

	fd = open("ghost", O_RDWR | O_CREAT);
	ft_putnbr_fd(1337, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, putnbrfd3, 4);
	unlink("./ghost");

	fd = open("ghost", O_RDWR | O_CREAT);
	ft_putnbr_fd(0, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, putnbrfd4, 1);
	unlink("./ghost");

	fd = open("ghost", O_RDWR | O_CREAT);
	ft_putnbr_fd(-0, fd);
	lseek(fd, SEEK_SET, 0);
	read(fd, putnbrfd5, 1);
	unlink("./ghost");

	if (strncmp(putnbrfd1, "-2147483648", 11))
		printf("[KO] putnbr_fd fails on int MIN\n");
	else if (strncmp(putnbrfd2, "2147483647", 10))
		printf("[KO] putnbr_fd fails on int MAX\n");
	else if (strncmp(putnbrfd3, "1337", 4))
		printf("[KO] putnbr_fd fails on test 3\n");
	else if (strncmp(putnbrfd4, "0", 1))
		printf("[KO] putnbr_fd fails on 0\n");
	else if (strncmp(putnbrfd5, "0", 1))
		printf("[KO] putnbr_fd fails on -0\n");
	else
		printf("[OK] ft_putnbr_fd\n");

	printf ("\n----- Bonus part-----\n");

	// //lstnew
	// t_list *new1;
	// new1 = ft_lstnew("monstro");
	// if (!new1)
	// 	printf("[KO] lstnew node does not exist\n");
	// else if (strcmp("monstro", (char *)new1->content))
	// 	printf("[KO] lstnew content was not written\n");
	// else
	// 	printf("[OK] ft_lstnew\n");
	// free(new1);

	// //lstadd_front
	// t_list *head;
	// char *add_front[] =	{"linked", "list", NULL};

	// head = ft_lstnew(("list"));
	// ft_lstadd_front(&head, ft_lstnew(("linked")));
	// if (lstsupport(head, add_front))
	// 	printf("[KO] content is not the same\n");
	// else
	// 	printf("[OK] ft_lstadd_front\n");
	// ft_lstclear(&head, del);

	// //lstsize
	// t_list *head2;

	// char *lstsize[] = {"has", "list", "this", "strings", "5", NULL};
	// i = 1;
	// head2 = ft_lstnew(lstsize[0]);
	// while (lstsize[i])
	// 	ft_lstadd_front(&head2, ft_lstnew(lstsize[i++]));
	// if (ft_lstsize(head2) != 5)
	// 	printf("[KO] lstsize returns incorrect size\n");
	// else
	// 	(printf("[OK] ft_lstsize\n"));

	// //lstlast
	// t_list *last;

	// last = ft_lstlast(head2);
	// if (last->next)
	// 	printf("[KO] lstlast->next pointer is not NULL\n");
	// else if (strcmp(last->content, "has"))
	// 	printf("[KO] strings of the last element do not match\n");
	// else
	// 	printf("[OK] ft_lstlast\n");

	// //lstadd_back
	// t_list *head3;

	// char *add_back[] = {"you", "are", "BALLER", NULL};
	// i = 0;
	// head3 = ft_lstnew(add_back[i++]);
	// while(add_back[i])
	// 	ft_lstadd_back(&head3, ft_lstnew(add_back[i++]));
	// if (lstsupport(head3, add_back))
	// 	printf("[KO] contents are not as expected\n");
	// else
	// 	printf("[OK] ft_lstadd_back\n");

	//lstdelone
	// t_list *delone = ft_lstnew("hello");
	// ft_lstdelone(delone, &del);
	// if (delone->content)
	// 	printf("[KO] content was not deleted\n");
	// else
	// 	printf("[OK] ft_delone\n");

	//lstclear
	}
