/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** map_file
*/

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

char *map_file(const char *filepath, off_t *size)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    void *buf;

    if (fd == -1)
        return NULL;
    if (fstat(fd, &st) == -1) {
        close(fd);
        return NULL;
    }
    buf = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == (void *)-1) {
        close(fd);
        return NULL;
    }
    *size = st.st_size;
    close(fd);
    return buf;
}
