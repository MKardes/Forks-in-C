#include "header.h"

int main()
{
	int	pid1;
	int	pid2;
	char	*tmp;
	char	buff[10];
	int	sum;
	int	size;
	int	fd;
	int	pfd1;
	int	pfd2;
	int	p1tmp;
	int	p2tmp;

	pid1 = fork();
	if (pid1 == 0)
	{
		//first child
		pid2 = fork();
		if (pid2 == 0)
		{
			//second child
			pid1 = fork();
			if (pid1 == 0)
			{
				//third child
				tmp = ft_itoa(getpid());
				fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
				tmp = ft_itoa(((((getpid() * getpid()) % 100) * getpid()) % 100)* getpid() % 100);
				write(fd, tmp, strlen(tmp));
				close(fd);
				exit(0);
			}
			else
			{
				pid2 = fork();
				if (pid2 == 0)
				{
					//third child
					tmp = ft_itoa(getpid());
					fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
					tmp = ft_itoa(((((getpid() * getpid()) % 100) * getpid()) % 100)* getpid() % 100);
					write(fd, tmp, strlen(tmp));
					close(fd);
					exit(0);
				}
				else
				{
					//second child last
					p1tmp = pid1;
					p2tmp = pid2;
					wait(&p1tmp);
					wait(&p2tmp);
					tmp = ft_itoa(getpid());
					fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
					pfd1 = open(ft_strjoin(ft_itoa(pid1), ".txt"), O_RDONLY);
					pfd2 = open(ft_strjoin(ft_itoa(pid2), ".txt"), O_RDONLY);
					size = read(pfd1, buff, 10);
					buff[size] = '\0';
					sum = atoi(buff);
					size = read(pfd2, buff, 10);
					buff[size] = '\0';
					sum += atoi(buff);
					tmp = ft_itoa(sum);
					write(fd, tmp, strlen(tmp));
					close(fd);
					close(pfd1);
					close(pfd2);
					exit(0);
				}
			}
		}
		else
		{
			pid1 = fork();
			if (pid1 == 0)
			{
				//second child
				pid2 = fork();
				if (pid2 == 0)
				{
					//third child
					tmp = ft_itoa(getpid());
					fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
					tmp = ft_itoa(((((getpid() * getpid()) % 100) * getpid()) % 100)* getpid() % 100);
					write(fd, tmp, strlen(tmp));
					close(fd);
					exit(0);
				}
				else
				{
					pid1 = fork();
					if (pid1 == 0)
					{
						//third child
						tmp = ft_itoa(getpid());
						fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
						tmp = ft_itoa(((((getpid() * getpid()) % 100) * getpid()) % 100)* getpid() % 100);
						write(fd, tmp, strlen(tmp));
						close(fd);
						exit(0);
					}
					else
					{
						//second child last
						p1tmp = pid1;
						p2tmp = pid2;
						wait(&p1tmp);
						wait(&p2tmp);
						tmp = ft_itoa(getpid());
						fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
						pfd1 = open(ft_strjoin(ft_itoa(pid1), ".txt"), O_RDONLY);
						pfd2 = open(ft_strjoin(ft_itoa(pid2), ".txt"), O_RDONLY);
						size = read(pfd1, buff, 10);
						buff[size] = '\0';
						sum = atoi(buff);
						size = read(pfd2, buff, 10);
						buff[size] = '\0';
						sum += atoi(buff);
						tmp = ft_itoa(sum);
						write(fd, tmp, strlen(tmp));
						close(fd);
						close(pfd1);
						close(pfd2);
						exit(0);
					}
				}
			}
			else
			{
				//first child last
				p1tmp = pid1;
				p2tmp = pid2;
				wait(&p1tmp);
				wait(&p2tmp);
				tmp = ft_itoa(getpid());
				fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
				pfd1 = open(ft_strjoin(ft_itoa(pid1), ".txt"), O_RDONLY);
				pfd2 = open(ft_strjoin(ft_itoa(pid2), ".txt"), O_RDONLY);
				size = read(pfd1, buff, 10);
				buff[size] = '\0';
				sum = atoi(buff);
				size = read(pfd2, buff, 10);
				buff[size] = '\0';
				sum += atoi(buff);
				tmp = ft_itoa(sum);
				write(fd, tmp, strlen(tmp));
				close(fd);
				close(pfd1);
				close(pfd2);
				exit(0);
			}
		}
	}
	else
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			//first child
			pid1 = fork();
			if (pid1 > 0)
			{
				pid2 = fork();
				if (pid2 == 0)
				{
					
					//second child
					pid1 = fork();
					if (pid1 > 0)
					{
						pid2 = fork();
						if (pid2 == 0)
						{
							//third child
							tmp = ft_itoa(getpid());
							fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
							tmp = ft_itoa(((((getpid() * getpid()) % 100) * getpid()) % 100)* getpid() % 100);
							write(fd, tmp, strlen(tmp));
							close(fd);
							exit(0);
						}
						else
						{
							//second child last
							p1tmp = pid1;
							p2tmp = pid2;
							wait(&p1tmp);
							wait(&p2tmp);
							tmp = ft_itoa(getpid());
							fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
							pfd1 = open(ft_strjoin(ft_itoa(pid1), ".txt"), O_RDONLY);
							pfd2 = open(ft_strjoin(ft_itoa(pid2), ".txt"), O_RDONLY);
							size = read(pfd1, buff, 10);
							buff[size] = '\0';
							sum = atoi(buff);
							size = read(pfd2, buff, 10);
							buff[size] = '\0';
							sum += atoi(buff);
							tmp = ft_itoa(sum);
							write(fd, tmp, strlen(tmp));
							close(fd);
							close(pfd1);
							close(pfd2);
							exit(0);
						}
					}
					else
					{
						//third child
						tmp = ft_itoa(getpid());
						fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
						tmp = ft_itoa(((((getpid() * getpid()) % 100) * getpid()) % 100)* getpid() % 100);
						write(fd, tmp, strlen(tmp));
						close(fd);
						exit(0);
					}
				}
				else
				{
					//first child last
					p1tmp = pid1;
					p2tmp = pid2;
					wait(&p1tmp);
					wait(&p2tmp);
					tmp = ft_itoa(getpid());
					fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
					pfd1 = open(ft_strjoin(ft_itoa(pid1), ".txt"), O_RDONLY);
					pfd2 = open(ft_strjoin(ft_itoa(pid2), ".txt"), O_RDONLY);
					size = read(pfd1, buff, 10);
					buff[size] = '\0';
					sum = atoi(buff);
					size = read(pfd2, buff, 10);
					buff[size] = '\0';
					sum += atoi(buff);
					tmp = ft_itoa(sum);
					write(fd, tmp, strlen(tmp));
					close(fd);
					close(pfd1);
					close(pfd2);
					exit(0);
				}
			}
			else
			{
				//second child
				pid2 = fork();
				if (pid2 == 0)
				{
					//third child
					tmp = ft_itoa(getpid());
					fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
					tmp = ft_itoa(((((getpid() * getpid()) % 100) * getpid()) % 100)* getpid() % 100);
					write(fd, tmp, strlen(tmp));
					close(fd);
					exit(0);
				}
				else
				{
					pid1 = fork();
					if (pid1 == 0)
					{
						//third child
						tmp = ft_itoa(getpid());
						fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
						tmp = ft_itoa(((((getpid() * getpid()) % 100) * getpid()) % 100)* getpid() % 100);
						write(fd, tmp, strlen(tmp));
						close(fd);
						exit(0);
					}
					else
					{
						//second child last
						p1tmp = pid1;
						p2tmp = pid2;
						wait(&p1tmp);
						wait(&p2tmp);
						tmp = ft_itoa(getpid());
						fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
						pfd1 = open(ft_strjoin(ft_itoa(pid1), ".txt"), O_RDONLY);
						pfd2 = open(ft_strjoin(ft_itoa(pid2), ".txt"), O_RDONLY);
						size = read(pfd1, buff, 10);
						buff[size] = '\0';
						sum = atoi(buff);
						size = read(pfd2, buff, 10);
						buff[size] = '\0';
						sum += atoi(buff);
						tmp = ft_itoa(sum);
						write(fd, tmp, strlen(tmp));
						close(fd);
						close(pfd1);
						close(pfd2);
						exit(0);
					}
				}
			}
		}
		else
		{
			//main proccess
			p1tmp = pid1;
			p2tmp = pid2;
			wait(&p1tmp);
			wait(&p2tmp);
			tmp = ft_itoa(getpid());
			fd = open(ft_strjoin(tmp, ".txt"), O_CREAT | O_RDWR, 0777);
			pfd1 = open(ft_strjoin(ft_itoa(pid1), ".txt"), O_RDONLY);
			pfd2 = open(ft_strjoin(ft_itoa(pid2), ".txt"), O_RDONLY);
			size = read(pfd1, buff, 10);
			buff[size] = '\0';
			sum = atoi(buff);
			size = read(pfd2, buff, 10);
			buff[size] = '\0';
			sum += atoi(buff);
			tmp = ft_itoa(sum);
			write(fd, tmp, strlen(tmp));
			close(fd);
			close(pfd1);
			close(pfd2);
			exit(0);
		}
	}
}
