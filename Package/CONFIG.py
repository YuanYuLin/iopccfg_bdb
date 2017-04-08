import os
import ops

def MAIN(pkg_name, pkg_repo):
    print pkg_name
    print pkg_repo
    macros = []
    major = 1
    minor = 0
    aux = 0
    with open("/tmp/version.h.new", 'w') as h_new_file:
        with open(pkg_repo + "/version.h") as h_file:
            for line in h_file:
                found = 0
                line = line.strip()
                if line.startswith('#define'):
                    macros = line.split()
                    print macros
                    macro = macros[1]
                    print macro
                    if macro == 'MAJOR_NUM':
                        major = int(macro[2])
                        found = 1
                    if macro == 'MINOR_NUM':
                        minor = int(macro[2])
                        found = 1
                    if macro == 'AUX_NUM':
                        aux = int(macro[2])
                        found = 1

                if not found:
                    h_new_file.write(line)
                    h_new_file.write(os.linesep)

        h_new_file.write('#define MAJOR_NUM ' + str(major))
        h_new_file.write(os.linesep)
        h_new_file.write('#define MINOR_NUM ' + str(minor))
        h_new_file.write(os.linesep)
        h_new_file.write('#define AUX_NUM ' + str(aux))
        h_new_file.write(os.linesep)

