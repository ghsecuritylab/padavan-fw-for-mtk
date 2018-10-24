/* DO NOT EDIT. This file is generated from applets.src.h */
/* vi: set sw=4 ts=4: */
/*
 * applets.h - a listing of all busybox applets.
 *
 * If you write a new applet, you need to add an entry to this list to make
 * busybox aware of it.
 */

/*
name  - applet name as it is typed on command line
help  - applet name, converted to C (ether-wake: help = ether_wake)
main  - corresponding <applet>_main to call (bzcat: main = bunzip2)
l     - location to install link to: [/usr]/[s]bin
s     - suid type:
        BB_SUID_REQUIRE: will complain if busybox isn't suid
        and is run by non-root (applet_main() will not be called at all)
        BB_SUID_DROP: will drop suid prior to applet_main()
        BB_SUID_MAYBE: neither of the above
        (every instance of BB_SUID_REQUIRE and BB_SUID_MAYBE
        needs to be justified in comment)
        NB: please update FEATURE_SUID help text whenever you add/remove
        BB_SUID_REQUIRE or BB_SUID_MAYBE applet.
*/

#if defined(PROTOTYPES)
# define APPLET(name,l,s)                    int name##_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
# define APPLET_ODDNAME(name,main,l,s,help)  int main##_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
# define APPLET_NOEXEC(name,main,l,s,help)   int main##_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
# define APPLET_NOFORK(name,main,l,s,help)   int main##_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;

#elif defined(NAME_MAIN)
# define APPLET(name,l,s)                    name name##_main
# define APPLET_ODDNAME(name,main,l,s,help)  name main##_main
# define APPLET_NOEXEC(name,main,l,s,help)   name main##_main
# define APPLET_NOFORK(name,main,l,s,help)   name main##_main

#elif defined(MAKE_USAGE) && ENABLE_FEATURE_VERBOSE_USAGE
# define APPLET(name,l,s)                    MAKE_USAGE(#name, name##_trivial_usage name##_full_usage)
# define APPLET_ODDNAME(name,main,l,s,help)  MAKE_USAGE(#name, help##_trivial_usage help##_full_usage)
# define APPLET_NOEXEC(name,main,l,s,help)   MAKE_USAGE(#name, help##_trivial_usage help##_full_usage)
# define APPLET_NOFORK(name,main,l,s,help)   MAKE_USAGE(#name, help##_trivial_usage help##_full_usage)

#elif defined(MAKE_USAGE) && !ENABLE_FEATURE_VERBOSE_USAGE
# define APPLET(name,l,s)                    MAKE_USAGE(#name, name##_trivial_usage)
# define APPLET_ODDNAME(name,main,l,s,help)  MAKE_USAGE(#name, help##_trivial_usage)
# define APPLET_NOEXEC(name,main,l,s,help)   MAKE_USAGE(#name, help##_trivial_usage)
# define APPLET_NOFORK(name,main,l,s,help)   MAKE_USAGE(#name, help##_trivial_usage)

#elif defined(MAKE_LINKS)
# define APPLET(name,l,c)                    LINK l name
# define APPLET_ODDNAME(name,main,l,s,help)  LINK l name
# define APPLET_NOEXEC(name,main,l,s,help)   LINK l name
# define APPLET_NOFORK(name,main,l,s,help)   LINK l name

#elif defined(MAKE_SUID)
# define APPLET(name,l,s)                    SUID s l name
# define APPLET_ODDNAME(name,main,l,s,help)  SUID s l name
# define APPLET_NOEXEC(name,main,l,s,help)   SUID s l name
# define APPLET_NOFORK(name,main,l,s,help)   SUID s l name

#else
  static struct bb_applet applets[] = { /*    name, main, location, need_suid */
# define APPLET(name,l,s)                    { #name, #name, l, s },
# define APPLET_ODDNAME(name,main,l,s,help)  { #name, #main, l, s },
# define APPLET_NOEXEC(name,main,l,s,help)   { #name, #main, l, s, 1 },
# define APPLET_NOFORK(name,main,l,s,help)   { #name, #main, l, s, 1, 1 },
#endif

#if ENABLE_INSTALL_NO_USR
# define BB_DIR_USR_BIN BB_DIR_BIN
# define BB_DIR_USR_SBIN BB_DIR_SBIN
#endif


IF_AR(APPLET(ar, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UNCOMPRESS(APPLET(uncompress, BB_DIR_BIN, BB_SUID_DROP))
IF_GUNZIP(APPLET(gunzip, BB_DIR_BIN, BB_SUID_DROP))
IF_ZCAT(APPLET_ODDNAME(zcat, gunzip, BB_DIR_BIN, BB_SUID_DROP, zcat))
IF_BUNZIP2(APPLET(bunzip2, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_BZCAT(APPLET_ODDNAME(bzcat, bunzip2, BB_DIR_USR_BIN, BB_SUID_DROP, bzcat))
IF_UNLZMA(APPLET(unlzma, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_LZCAT(APPLET_ODDNAME(lzcat, unlzma, BB_DIR_USR_BIN, BB_SUID_DROP, lzcat))
IF_LZMA( APPLET_ODDNAME(lzma,  unlzma, BB_DIR_USR_BIN, BB_SUID_DROP, lzma))
IF_UNXZ(APPLET(unxz, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_XZCAT(APPLET_ODDNAME(xzcat, unxz, BB_DIR_USR_BIN, BB_SUID_DROP, xzcat))
IF_XZ(   APPLET_ODDNAME(xz,    unxz, BB_DIR_USR_BIN, BB_SUID_DROP, xz))
IF_BZIP2(APPLET(bzip2, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CPIO(APPLET(cpio, BB_DIR_BIN, BB_SUID_DROP))
IF_DPKG(APPLET(dpkg, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DPKG_DEB(APPLET_ODDNAME(dpkg-deb, dpkg_deb, BB_DIR_USR_BIN, BB_SUID_DROP, dpkg_deb))
IF_GZIP(APPLET(gzip, BB_DIR_BIN, BB_SUID_DROP))
IF_LZOP(APPLET(lzop, BB_DIR_BIN, BB_SUID_DROP))
IF_UNLZOP( APPLET_ODDNAME(unlzop,  lzop, BB_DIR_USR_BIN, BB_SUID_DROP, unlzop))
IF_LZOPCAT(APPLET_ODDNAME(lzopcat, lzop, BB_DIR_USR_BIN, BB_SUID_DROP, lzopcat))
IF_RPM(APPLET(rpm, BB_DIR_BIN, BB_SUID_DROP))
IF_RPM2CPIO(APPLET(rpm2cpio, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TAR(APPLET(tar, BB_DIR_BIN, BB_SUID_DROP))
IF_UNZIP(APPLET(unzip, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CHVT(APPLET_NOEXEC(chvt, chvt, BB_DIR_USR_BIN, BB_SUID_DROP, chvt))
IF_CLEAR(APPLET_NOFORK(clear, clear, BB_DIR_USR_BIN, BB_SUID_DROP, clear))
IF_DEALLOCVT(APPLET_NOEXEC(deallocvt, deallocvt, BB_DIR_USR_BIN, BB_SUID_DROP, deallocvt))
IF_DUMPKMAP(APPLET_NOEXEC(dumpkmap, dumpkmap, BB_DIR_BIN, BB_SUID_DROP, dumpkmap))
IF_FGCONSOLE(APPLET_NOEXEC(fgconsole, fgconsole, BB_DIR_USR_BIN, BB_SUID_DROP, fgconsole))
IF_KBD_MODE(APPLET_NOEXEC(kbd_mode, kbd_mode, BB_DIR_BIN, BB_SUID_DROP, kbd_mode))
IF_LOADFONT(APPLET_NOEXEC(loadfont, loadfont, BB_DIR_USR_SBIN, BB_SUID_DROP, loadfont))
IF_SETFONT(APPLET_NOEXEC(setfont, setfont, BB_DIR_USR_SBIN, BB_SUID_DROP, setfont))
IF_LOADKMAP(APPLET_NOEXEC(loadkmap, loadkmap, BB_DIR_SBIN, BB_SUID_DROP, loadkmap))
IF_OPENVT(APPLET(openvt, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_RESET(APPLET_NOEXEC(reset, reset, BB_DIR_USR_BIN, BB_SUID_DROP, reset))
IF_RESIZE(APPLET_NOEXEC(resize, resize, BB_DIR_USR_BIN, BB_SUID_DROP, resize))
IF_SETCONSOLE(APPLET_NOEXEC(setconsole, setconsole, BB_DIR_SBIN, BB_SUID_DROP, setconsole))
IF_SETKEYCODES(APPLET_NOEXEC(setkeycodes, setkeycodes, BB_DIR_USR_BIN, BB_SUID_DROP, setkeycodes))
IF_SETLOGCONS(APPLET_NOEXEC(setlogcons, setlogcons, BB_DIR_USR_SBIN, BB_SUID_DROP, setlogcons))
IF_SHOWKEY(APPLET(showkey, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_BASENAME(APPLET_NOFORK(basename, basename, BB_DIR_USR_BIN, BB_SUID_DROP, basename))
IF_CAT(APPLET(cat, BB_DIR_BIN, BB_SUID_DROP))
IF_CHGRP(APPLET_NOEXEC(chgrp, chgrp, BB_DIR_BIN, BB_SUID_DROP, chgrp))
IF_CHMOD(APPLET_NOEXEC(chmod, chmod, BB_DIR_BIN, BB_SUID_DROP, chmod))
IF_CHOWN(APPLET_NOEXEC(chown, chown, BB_DIR_BIN, BB_SUID_DROP, chown))
IF_CHROOT(APPLET_NOEXEC(chroot, chroot, BB_DIR_USR_SBIN, BB_SUID_DROP, chroot))
IF_CKSUM(APPLET_NOEXEC(cksum, cksum, BB_DIR_USR_BIN, BB_SUID_DROP, cksum))
IF_COMM(APPLET(comm, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CP(APPLET_NOEXEC(cp, cp, BB_DIR_BIN, BB_SUID_DROP, cp))
IF_CUT(APPLET_NOEXEC(cut, cut, BB_DIR_USR_BIN, BB_SUID_DROP, cut))
IF_DATE(APPLET_NOEXEC(date, date, BB_DIR_BIN, BB_SUID_DROP, date))
IF_DD(APPLET_NOEXEC(dd, dd, BB_DIR_BIN, BB_SUID_DROP, dd))
IF_DF(APPLET_NOEXEC(df, df, BB_DIR_BIN, BB_SUID_DROP, df))
IF_DIRNAME(APPLET_NOFORK(dirname, dirname, BB_DIR_USR_BIN, BB_SUID_DROP, dirname))
IF_DOS2UNIX(APPLET_NOEXEC(dos2unix, dos2unix, BB_DIR_USR_BIN, BB_SUID_DROP, dos2unix))
IF_UNIX2DOS(APPLET_NOEXEC(unix2dos, dos2unix, BB_DIR_USR_BIN, BB_SUID_DROP, unix2dos))
IF_DU(APPLET(du, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ECHO(APPLET_NOFORK(echo, echo, BB_DIR_BIN, BB_SUID_DROP, echo))
IF_ENV(APPLET_NOEXEC(env, env, BB_DIR_USR_BIN, BB_SUID_DROP, env))
IF_EXPAND(APPLET(expand, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UNEXPAND(APPLET_ODDNAME(unexpand, expand, BB_DIR_USR_BIN, BB_SUID_DROP, unexpand))
IF_EXPR(APPLET_NOEXEC(expr, expr, BB_DIR_USR_BIN, BB_SUID_DROP, expr))
IF_FACTOR(APPLET(factor, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_FALSE(APPLET_NOFORK(false, false, BB_DIR_BIN, BB_SUID_DROP, false))
IF_FOLD(APPLET_NOEXEC(fold, fold, BB_DIR_USR_BIN, BB_SUID_DROP, fold))
IF_FSYNC(APPLET_NOFORK(fsync, fsync, BB_DIR_BIN, BB_SUID_DROP, fsync))
IF_HEAD(APPLET_NOEXEC(head, head, BB_DIR_USR_BIN, BB_SUID_DROP, head))
IF_HOSTID(APPLET_NOFORK(hostid, hostid, BB_DIR_USR_BIN, BB_SUID_DROP, hostid))
IF_GROUPS(APPLET_NOEXEC(groups, id, BB_DIR_USR_BIN, BB_SUID_DROP, groups))
IF_ID(    APPLET_NOEXEC(id,     id, BB_DIR_USR_BIN, BB_SUID_DROP, id    ))
IF_INSTALL(APPLET(install, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_LINK(APPLET_NOFORK(link, link, BB_DIR_BIN, BB_SUID_DROP, link))
IF_LN(APPLET_NOEXEC(ln, ln, BB_DIR_BIN, BB_SUID_DROP, ln))
IF_LOGNAME(APPLET_NOFORK(logname, logname, BB_DIR_USR_BIN, BB_SUID_DROP, logname))
IF_LS(APPLET_NOEXEC(ls, ls, BB_DIR_BIN, BB_SUID_DROP, ls))
IF_MD5SUM(APPLET_NOEXEC(md5sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, md5sum))
IF_SHA1SUM(APPLET_NOEXEC(sha1sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, sha1sum))
IF_SHA3SUM(APPLET_NOEXEC(sha3sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, sha3sum))
IF_SHA256SUM(APPLET_NOEXEC(sha256sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, sha256sum))
IF_SHA512SUM(APPLET_NOEXEC(sha512sum, md5_sha1_sum, BB_DIR_USR_BIN, BB_SUID_DROP, sha512sum))
IF_MKDIR(APPLET_NOFORK(mkdir, mkdir, BB_DIR_BIN, BB_SUID_DROP, mkdir))
IF_MKFIFO(APPLET_NOEXEC(mkfifo, mkfifo, BB_DIR_USR_BIN, BB_SUID_DROP, mkfifo))
IF_MKNOD(APPLET_NOEXEC(mknod, mknod, BB_DIR_BIN, BB_SUID_DROP, mknod))
IF_MKTEMP(APPLET_NOEXEC(mktemp, mktemp, BB_DIR_BIN, BB_SUID_DROP, mktemp))
IF_MV(APPLET(mv, BB_DIR_BIN, BB_SUID_DROP))
IF_NICE(APPLET_NOEXEC(nice, nice, BB_DIR_BIN, BB_SUID_DROP, nice))
IF_NL(APPLET(nl, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_NOHUP(APPLET_NOEXEC(nohup, nohup, BB_DIR_USR_BIN, BB_SUID_DROP, nohup))
IF_NPROC(APPLET_NOFORK(nproc, nproc, BB_DIR_USR_BIN, BB_SUID_DROP, nproc))
IF_OD(APPLET(od, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_PASTE(APPLET_NOEXEC(paste, paste, BB_DIR_USR_BIN, BB_SUID_DROP, paste))
IF_PRINTENV(APPLET_NOFORK(printenv, printenv, BB_DIR_BIN, BB_SUID_DROP, printenv))
IF_PRINTF(APPLET_NOFORK(printf, printf, BB_DIR_USR_BIN, BB_SUID_DROP, printf))
IF_PWD(APPLET_NOFORK(pwd, pwd, BB_DIR_BIN, BB_SUID_DROP, pwd))
IF_READLINK(APPLET_NOFORK(readlink, readlink, BB_DIR_USR_BIN, BB_SUID_DROP, readlink))
IF_REALPATH(APPLET_NOFORK(realpath, realpath, BB_DIR_USR_BIN, BB_SUID_DROP, realpath))
IF_RM(APPLET_NOEXEC(rm, rm, BB_DIR_BIN, BB_SUID_DROP, rm))
IF_RMDIR(APPLET_NOFORK(rmdir, rmdir, BB_DIR_BIN, BB_SUID_DROP, rmdir))
IF_SEQ(APPLET_NOEXEC(seq, seq, BB_DIR_USR_BIN, BB_SUID_DROP, seq))
IF_SHRED(APPLET(shred, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SHUF(APPLET_NOEXEC(shuf, shuf, BB_DIR_USR_BIN, BB_SUID_DROP, shuf))
IF_SLEEP(APPLET(sleep, BB_DIR_BIN, BB_SUID_DROP))
IF_SORT(APPLET_NOEXEC(sort, sort, BB_DIR_USR_BIN, BB_SUID_DROP, sort))
IF_SPLIT(APPLET(split, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_STAT(APPLET_NOEXEC(stat, stat, BB_DIR_BIN, BB_SUID_DROP, stat))
IF_STTY(APPLET_NOEXEC(stty, stty, BB_DIR_BIN, BB_SUID_DROP, stty))
IF_SUM(APPLET(sum, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SYNC(APPLET_NOFORK(sync, sync, BB_DIR_BIN, BB_SUID_DROP, sync))
IF_TAC(APPLET_NOEXEC(tac, tac, BB_DIR_USR_BIN, BB_SUID_DROP, tac))
IF_TAIL(APPLET(tail, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TEE(APPLET(tee, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TEST(APPLET_NOFORK(test, test, BB_DIR_USR_BIN, BB_SUID_DROP, test))
IF_TEST1(APPLET_NOFORK([,   test, BB_DIR_USR_BIN, BB_SUID_DROP, test))
IF_TEST2(APPLET_NOFORK([[,  test, BB_DIR_USR_BIN, BB_SUID_DROP, test))
IF_TIMEOUT(APPLET(timeout, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TOUCH(APPLET_NOFORK(touch, touch, BB_DIR_BIN, BB_SUID_DROP, touch))
IF_TR(APPLET(tr, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TRUE(APPLET_NOFORK(true, true, BB_DIR_BIN, BB_SUID_DROP, true))
IF_TRUNCATE(APPLET_NOFORK(truncate, truncate, BB_DIR_USR_BIN, BB_SUID_DROP, truncate))
IF_TTY(APPLET_NOFORK(tty, tty, BB_DIR_USR_BIN, BB_SUID_DROP, tty))
IF_UNAME(APPLET_NOFORK(  uname, uname, BB_DIR_BIN, BB_SUID_DROP, uname))
IF_BB_ARCH(APPLET_NOFORK(arch,  uname, BB_DIR_BIN, BB_SUID_DROP, arch))
IF_UNIQ(APPLET(uniq, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UNLINK(APPLET_NOFORK(unlink, unlink, BB_DIR_USR_BIN, BB_SUID_DROP, unlink))
IF_USLEEP(APPLET_NOFORK(usleep, usleep, BB_DIR_BIN, BB_SUID_DROP, usleep))
IF_UUDECODE(APPLET(uudecode, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_BASE64(APPLET(base64, BB_DIR_BIN, BB_SUID_DROP))
IF_UUENCODE(APPLET(uuencode, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WC(APPLET(wc, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WHOAMI(APPLET_NOFORK(whoami, whoami, BB_DIR_USR_BIN, BB_SUID_DROP, whoami))
IF_USERS(APPLET_NOEXEC(users, who, BB_DIR_USR_BIN, BB_SUID_DROP, users))
IF_W(    APPLET_NOEXEC(w,     who, BB_DIR_USR_BIN, BB_SUID_DROP, w))
IF_WHO(  APPLET_NOEXEC(who,   who, BB_DIR_USR_BIN, BB_SUID_DROP, who))
IF_YES(APPLET_NOEXEC(yes, yes, BB_DIR_USR_BIN, BB_SUID_DROP, yes))
IF_PIPE_PROGRESS(APPLET(pipe_progress, BB_DIR_BIN, BB_SUID_DROP))
IF_RUN_PARTS(APPLET_ODDNAME(run-parts, run_parts, BB_DIR_BIN, BB_SUID_DROP, run_parts))
IF_START_STOP_DAEMON(APPLET_ODDNAME(start-stop-daemon, start_stop_daemon, BB_DIR_SBIN, BB_SUID_DROP, start_stop_daemon))
IF_WHICH(APPLET_NOFORK(which, which, BB_DIR_USR_BIN, BB_SUID_DROP, which))
IF_CHATTR(APPLET_NOEXEC(chattr, chattr, BB_DIR_BIN, BB_SUID_DROP, chattr))
IF_FSCK(APPLET(fsck, BB_DIR_SBIN, BB_SUID_DROP))
IF_LSATTR(APPLET_NOEXEC(lsattr, lsattr, BB_DIR_BIN, BB_SUID_DROP, lsattr))
IF_TUNE2FS(APPLET_NOEXEC(tune2fs, tune2fs, BB_DIR_SBIN, BB_SUID_DROP, tune2fs))
IF_AWK(APPLET_NOEXEC(awk, awk, BB_DIR_USR_BIN, BB_SUID_DROP, awk))
IF_CMP(APPLET(cmp, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DIFF(APPLET(diff, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ED(APPLET(ed, BB_DIR_BIN, BB_SUID_DROP))
IF_PATCH(APPLET(patch, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SED(APPLET(sed, BB_DIR_BIN, BB_SUID_DROP))
IF_VI(APPLET(vi, BB_DIR_BIN, BB_SUID_DROP))
IF_FIND(APPLET_NOEXEC(find, find, BB_DIR_USR_BIN, BB_SUID_DROP, find))
IF_GREP(APPLET(grep, BB_DIR_BIN, BB_SUID_DROP))
IF_EGREP(APPLET_ODDNAME(egrep, grep, BB_DIR_BIN, BB_SUID_DROP, egrep))
IF_FGREP(APPLET_ODDNAME(fgrep, grep, BB_DIR_BIN, BB_SUID_DROP, fgrep))
IF_XARGS(APPLET_NOEXEC(xargs, xargs, BB_DIR_USR_BIN, BB_SUID_DROP, xargs))
IF_BOOTCHARTD(APPLET(bootchartd, BB_DIR_SBIN, BB_SUID_DROP))
IF_HALT(APPLET(halt, BB_DIR_SBIN, BB_SUID_DROP))
IF_POWEROFF(APPLET_ODDNAME(poweroff, halt, BB_DIR_SBIN, BB_SUID_DROP, poweroff))
IF_REBOOT(  APPLET_ODDNAME(reboot,   halt, BB_DIR_SBIN, BB_SUID_DROP, reboot))
IF_INIT(APPLET(init, BB_DIR_SBIN, BB_SUID_DROP))
IF_LINUXRC(APPLET_ODDNAME(linuxrc, init, BB_DIR_ROOT, BB_SUID_DROP, linuxrc))
IF_NUKE(APPLET_NOEXEC(nuke, nuke, BB_DIR_BIN, BB_SUID_DROP, nuke))
IF_RESUME(APPLET_NOEXEC(resume, resume, BB_DIR_BIN, BB_SUID_DROP, resume))
IF_BUSYBOX(IF_FEATURE_SH_STANDALONE(IF_FEATURE_TAB_COMPLETION(APPLET(busybox, BB_DIR_BIN, BB_SUID_MAYBE))))
IF_UNIT_TEST(APPLET(unit, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ADDGROUP(APPLET_NOEXEC(addgroup, addgroup, BB_DIR_USR_SBIN, BB_SUID_DROP, addgroup))
IF_ADD_SHELL(   APPLET_NOEXEC(add-shell   , add_remove_shell, BB_DIR_USR_SBIN, BB_SUID_DROP, add_shell   ))
IF_REMOVE_SHELL(APPLET_NOEXEC(remove-shell, add_remove_shell, BB_DIR_USR_SBIN, BB_SUID_DROP, remove_shell))
IF_ADDUSER(APPLET_NOEXEC(adduser, adduser, BB_DIR_USR_SBIN, BB_SUID_DROP, adduser))
IF_CHPASSWD(APPLET(chpasswd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_CRYPTPW( APPLET_NOEXEC(cryptpw,  cryptpw, BB_DIR_USR_BIN, BB_SUID_DROP, cryptpw))
IF_MKPASSWD(APPLET_NOEXEC(mkpasswd, cryptpw, BB_DIR_USR_BIN, BB_SUID_DROP, cryptpw))
IF_DELUSER( APPLET_NOEXEC(deluser,  deluser, BB_DIR_USR_SBIN, BB_SUID_DROP, deluser))
IF_DELGROUP(APPLET_NOEXEC(delgroup, deluser, BB_DIR_USR_SBIN, BB_SUID_DROP, delgroup))
IF_GETTY(APPLET(getty, BB_DIR_SBIN, BB_SUID_DROP))
/* Needs to be run by root or be suid root - needs to change uid and gid: */
IF_LOGIN(APPLET(login, BB_DIR_BIN, BB_SUID_REQUIRE))
/* Needs to be run by root or be suid root - needs to change /etc/{passwd,shadow}: */
IF_PASSWD(APPLET(passwd, BB_DIR_BIN, BB_SUID_REQUIRE))
/* Needs to be run by root or be suid root - needs to change uid and gid: */
IF_SU(APPLET(su, BB_DIR_BIN, BB_SUID_REQUIRE))
IF_SULOGIN(APPLET_NOEXEC(sulogin, sulogin, BB_DIR_SBIN, BB_SUID_DROP, sulogin))
/* Needs to be run by root or be suid root - needs to change uid and gid: */
IF_VLOCK(APPLET(vlock, BB_DIR_USR_BIN, BB_SUID_REQUIRE))
IF_MAKEMIME(APPLET(makemime, BB_DIR_BIN, BB_SUID_DROP))
IF_POPMAILDIR(APPLET(popmaildir, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_REFORMIME(APPLET(reformime, BB_DIR_BIN, BB_SUID_DROP))
IF_SENDMAIL(APPLET(sendmail, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_ADJTIMEX(APPLET_NOFORK(adjtimex, adjtimex, BB_DIR_SBIN, BB_SUID_DROP, adjtimex))
IF_BBCONFIG(APPLET(bbconfig, BB_DIR_BIN, BB_SUID_DROP))
IF_BEEP(APPLET(beep, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CHAT(APPLET(chat, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_CONSPY(APPLET(conspy, BB_DIR_BIN, BB_SUID_DROP))
IF_CROND(APPLET(crond, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_CRONTAB(APPLET(crontab, BB_DIR_USR_BIN, BB_SUID_REQUIRE))
IF_DC(APPLET(dc, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_DEVFSD(APPLET(devfsd, BB_DIR_SBIN, BB_SUID_DROP))
IF_DEVMEM(APPLET(devmem, BB_DIR_SBIN, BB_SUID_DROP))
IF_FBSPLASH(APPLET(fbsplash, BB_DIR_SBIN, BB_SUID_DROP))
IF_FLASHCP(APPLET(flashcp, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FLASH_ERASEALL(APPLET(flash_eraseall, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FLASH_LOCK(  APPLET_ODDNAME(flash_lock,   flash_lock_unlock, BB_DIR_USR_SBIN, BB_SUID_DROP, flash_lock))
IF_FLASH_UNLOCK(APPLET_ODDNAME(flash_unlock, flash_lock_unlock, BB_DIR_USR_SBIN, BB_SUID_DROP, flash_unlock))
IF_HDPARM(APPLET(hdparm, BB_DIR_SBIN, BB_SUID_DROP))
IF_HEXEDIT(APPLET(hexedit, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_I2CGET(APPLET(i2cget, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_I2CSET(APPLET(i2cset, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_I2CDUMP(APPLET(i2cdump, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_I2CDETECT(APPLET(i2cdetect, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_INOTIFYD(APPLET(inotifyd, BB_DIR_SBIN, BB_SUID_DROP))
IF_LESS(APPLET(less, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_LSSCSI(APPLET_NOEXEC(lsscsi, lsscsi, BB_DIR_USR_BIN, BB_SUID_DROP, lsscsi))
IF_MAKEDEVS(APPLET_NOEXEC(makedevs, makedevs, BB_DIR_SBIN, BB_SUID_DROP, makedevs))
IF_MAN(APPLET(man, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_MICROCOM(APPLET(microcom, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_MT(APPLET(mt, BB_DIR_BIN, BB_SUID_DROP))
IF_NANDWRITE(APPLET(nandwrite, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_NANDDUMP(APPLET_ODDNAME(nanddump, nandwrite, BB_DIR_USR_SBIN, BB_SUID_DROP, nanddump))
IF_PARTPROBE(APPLET_NOEXEC(partprobe, partprobe, BB_DIR_USR_SBIN, BB_SUID_DROP, partprobe))
IF_RAIDAUTORUN(APPLET_NOEXEC(raidautorun, raidautorun, BB_DIR_SBIN, BB_SUID_DROP, raidautorun))
IF_READAHEAD(APPLET(readahead, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_RFKILL(APPLET(rfkill, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_RUNLEVEL(APPLET_NOEXEC(runlevel, runlevel, BB_DIR_SBIN, BB_SUID_DROP, runlevel))
IF_RX(APPLET(rx, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SETFATTR(APPLET_NOEXEC(setfattr, setfattr, BB_DIR_USR_BIN, BB_SUID_DROP, setfattr))
IF_SETSERIAL(APPLET_NOEXEC(setserial, setserial, BB_DIR_BIN, BB_SUID_DROP, setserial))
IF_STRINGS(APPLET(strings, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TIME(APPLET(time, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TTYSIZE(APPLET_NOFORK(ttysize, ttysize, BB_DIR_USR_BIN, BB_SUID_DROP, ttysize))
IF_UBIRENAME(APPLET(ubirename, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_UBIATTACH(   APPLET_ODDNAME(ubiattach, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubiattach))
IF_UBIDETACH(   APPLET_ODDNAME(ubidetach, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubidetach))
IF_UBIMKVOL(    APPLET_ODDNAME(ubimkvol,  ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubimkvol))
IF_UBIRMVOL(    APPLET_ODDNAME(ubirmvol,  ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubirmvol))
IF_UBIRSVOL(    APPLET_ODDNAME(ubirsvol,  ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubirsvol))
IF_UBIUPDATEVOL(APPLET_ODDNAME(ubiupdatevol, ubi_tools, BB_DIR_USR_SBIN, BB_SUID_DROP, ubiupdatevol))
IF_VOLNAME(APPLET(volname, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WATCHDOG(APPLET(watchdog, BB_DIR_SBIN, BB_SUID_DROP))
IF_DEPMOD(IF_NOT_MODPROBE_SMALL(APPLET(depmod, BB_DIR_SBIN, BB_SUID_DROP)))
IF_INSMOD(IF_NOT_MODPROBE_SMALL(APPLET_NOEXEC(insmod, insmod, BB_DIR_SBIN, BB_SUID_DROP, insmod)))
IF_LSMOD(IF_NOT_MODPROBE_SMALL(APPLET_NOEXEC(lsmod, lsmod, BB_DIR_SBIN, BB_SUID_DROP, lsmod)))
IF_MODINFO(APPLET_NOEXEC(modinfo, modinfo, BB_DIR_SBIN, BB_SUID_DROP, modinfo))
IF_MODPROBE(IF_NOT_MODPROBE_SMALL(APPLET_NOEXEC(modprobe, modprobe, BB_DIR_SBIN, BB_SUID_DROP, modprobe)))
IF_LSMOD(   IF_MODPROBE_SMALL(APPLET_NOEXEC( lsmod,    lsmod,    BB_DIR_SBIN, BB_SUID_DROP, lsmod   )))
IF_MODPROBE(IF_MODPROBE_SMALL(APPLET_NOEXEC( modprobe, modprobe, BB_DIR_SBIN, BB_SUID_DROP, modprobe)))
IF_DEPMOD(  IF_MODPROBE_SMALL(APPLET_ODDNAME(depmod,   modprobe, BB_DIR_SBIN, BB_SUID_DROP, depmod  )))
IF_INSMOD(  IF_MODPROBE_SMALL(APPLET_NOEXEC( insmod,   modprobe, BB_DIR_SBIN, BB_SUID_DROP, insmod  )))
IF_RMMOD(   IF_MODPROBE_SMALL(APPLET_NOEXEC( rmmod,    modprobe, BB_DIR_SBIN, BB_SUID_DROP, rmmod   )))
IF_RMMOD(IF_NOT_MODPROBE_SMALL(APPLET_NOEXEC(rmmod, rmmod, BB_DIR_SBIN, BB_SUID_DROP, rmmod)))
IF_ARP(APPLET(arp, BB_DIR_SBIN, BB_SUID_DROP))
IF_ARPING(APPLET(arping, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_BRCTL(APPLET_NOEXEC(brctl, brctl, BB_DIR_USR_SBIN, BB_SUID_DROP, brctl))
IF_DNSD(APPLET(dnsd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_ETHER_WAKE(APPLET_ODDNAME(ether-wake, ether_wake, BB_DIR_USR_SBIN, BB_SUID_DROP, ether_wake))
IF_FTPD(APPLET(ftpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FTPGET(APPLET_ODDNAME(ftpget, ftpgetput, BB_DIR_USR_BIN, BB_SUID_DROP, ftpget))
IF_FTPPUT(APPLET_ODDNAME(ftpput, ftpgetput, BB_DIR_USR_BIN, BB_SUID_DROP, ftpput))
IF_DNSDOMAINNAME(APPLET_NOEXEC(dnsdomainname, hostname, BB_DIR_BIN, BB_SUID_DROP, dnsdomainname))
IF_HOSTNAME(     APPLET_NOEXEC(hostname,      hostname, BB_DIR_BIN, BB_SUID_DROP, hostname     ))
IF_HTTPD(APPLET(httpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_IFCONFIG(APPLET(ifconfig, BB_DIR_SBIN, BB_SUID_DROP))
IF_IFENSLAVE(APPLET_NOEXEC(ifenslave, ifenslave, BB_DIR_SBIN, BB_SUID_DROP, ifenslave))
IF_IFPLUGD(APPLET(ifplugd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_IFUP(  APPLET_ODDNAME(ifup,   ifupdown, BB_DIR_SBIN, BB_SUID_DROP, ifup))
IF_IFDOWN(APPLET_ODDNAME(ifdown, ifupdown, BB_DIR_SBIN, BB_SUID_DROP, ifdown))
IF_INETD(APPLET(inetd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_IP(      APPLET_NOEXEC(ip      , ip      , BB_DIR_SBIN, BB_SUID_DROP, ip      ))
IF_IPADDR(  APPLET_NOEXEC(ipaddr  , ipaddr  , BB_DIR_SBIN, BB_SUID_DROP, ipaddr  ))
IF_IPLINK(  APPLET_NOEXEC(iplink  , iplink  , BB_DIR_SBIN, BB_SUID_DROP, iplink  ))
IF_IPROUTE( APPLET_NOEXEC(iproute , iproute , BB_DIR_SBIN, BB_SUID_DROP, iproute ))
IF_IPRULE(  APPLET_NOEXEC(iprule  , iprule  , BB_DIR_SBIN, BB_SUID_DROP, iprule  ))
IF_IPTUNNEL(APPLET_NOEXEC(iptunnel, iptunnel, BB_DIR_SBIN, BB_SUID_DROP, iptunnel))
IF_IPNEIGH( APPLET_NOEXEC(ipneigh , ipneigh , BB_DIR_SBIN, BB_SUID_DROP, ipneigh ))
IF_IPCALC(APPLET_NOEXEC(ipcalc, ipcalc, BB_DIR_BIN, BB_SUID_DROP, ipcalc))
IF_FAKEIDENTD(APPLET(fakeidentd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_NAMEIF(APPLET_NOEXEC(nameif, nameif, BB_DIR_SBIN, BB_SUID_DROP, nameif))
IF_NBDCLIENT(APPLET_NOEXEC(nbd-client, nbdclient, BB_DIR_USR_SBIN, BB_SUID_DROP, nbdclient))
IF_NC(APPLET(nc, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_NETCAT(APPLET_ODDNAME(netcat, nc,  BB_DIR_USR_BIN, BB_SUID_DROP, nc))
IF_NETSTAT(APPLET(netstat, BB_DIR_BIN, BB_SUID_DROP))
IF_NSLOOKUP(APPLET(nslookup, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_NTPD(APPLET(ntpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_PING(APPLET(ping, BB_DIR_BIN, BB_SUID_MAYBE))
IF_PING6(APPLET(ping6, BB_DIR_BIN, BB_SUID_MAYBE))
IF_PSCAN(APPLET(pscan, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ROUTE(APPLET(route, BB_DIR_SBIN, BB_SUID_DROP))
IF_SLATTACH(APPLET(slattach, BB_DIR_SBIN, BB_SUID_DROP))
IF_SSL_CLIENT(APPLET(ssl_client, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TCPSVD(APPLET_ODDNAME(tcpsvd, tcpudpsvd, BB_DIR_USR_BIN, BB_SUID_DROP, tcpsvd))
IF_UDPSVD(APPLET_ODDNAME(udpsvd, tcpudpsvd, BB_DIR_USR_BIN, BB_SUID_DROP, udpsvd))
IF_TELNET(APPLET(telnet, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TELNETD(APPLET(telnetd, BB_DIR_USR_SBIN, BB_SUID_DROP))
#if ENABLE_FEATURE_TFTP_GET || ENABLE_FEATURE_TFTP_PUT
IF_TFTP(APPLET(tftp, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_TFTPD(APPLET(tftpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
#endif
IF_TRACEROUTE(APPLET(traceroute, BB_DIR_BIN, BB_SUID_MAYBE))
IF_TRACEROUTE6(APPLET(traceroute6, BB_DIR_BIN, BB_SUID_MAYBE))
IF_TUNCTL(APPLET_NOEXEC(tunctl, tunctl, BB_DIR_SBIN, BB_SUID_DROP, tunctl))
IF_VCONFIG(APPLET_NOEXEC(vconfig, vconfig, BB_DIR_SBIN, BB_SUID_DROP, vconfig))
IF_WGET(APPLET(wget, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WHOIS(APPLET(whois, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_ZCIP(APPLET(zcip, BB_DIR_SBIN, BB_SUID_DROP))
IF_LPD(APPLET(lpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_LPQ(APPLET_ODDNAME(lpq, lpqr, BB_DIR_USR_BIN, BB_SUID_DROP, lpq))
IF_LPR(APPLET_ODDNAME(lpr, lpqr, BB_DIR_USR_BIN, BB_SUID_DROP, lpr))
IF_FREE(APPLET_NOFORK(free, free, BB_DIR_USR_BIN, BB_SUID_DROP, free))
IF_FUSER(APPLET(fuser, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_IOSTAT(APPLET(iostat, BB_DIR_BIN, BB_SUID_DROP))
IF_KILL(    APPLET_NOFORK(kill,     kill, BB_DIR_BIN,      BB_SUID_DROP, kill))
IF_KILLALL( APPLET_NOFORK(killall,  kill, BB_DIR_USR_BIN,  BB_SUID_DROP, killall))
IF_KILLALL5(APPLET_NOFORK(killall5, kill, BB_DIR_USR_SBIN, BB_SUID_DROP, killall5))
IF_LSOF(APPLET(lsof, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_MPSTAT(APPLET(mpstat, BB_DIR_BIN, BB_SUID_DROP))
IF_NMETER(APPLET(nmeter, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_PGREP(APPLET_ODDNAME(pgrep, pgrep, BB_DIR_USR_BIN, BB_SUID_DROP, pgrep))
IF_PKILL(APPLET_ODDNAME(pkill, pgrep, BB_DIR_USR_BIN, BB_SUID_DROP, pkill))
IF_PIDOF(APPLET(pidof, BB_DIR_BIN, BB_SUID_DROP))
IF_PMAP(APPLET(pmap, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_POWERTOP(APPLET(powertop, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_PS(    APPLET_NOEXEC(ps,     ps,  BB_DIR_BIN, BB_SUID_DROP, ps))
IF_MINIPS(APPLET_NOEXEC(minips, ps,  BB_DIR_BIN, BB_SUID_DROP, ps))
IF_PSTREE(APPLET_NOEXEC(pstree, pstree, BB_DIR_USR_BIN, BB_SUID_DROP, pstree))
IF_PWDX(APPLET_NOFORK(pwdx, pwdx, BB_DIR_USR_BIN, BB_SUID_DROP, pwdx))
IF_SMEMCAP(APPLET(smemcap, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_BB_SYSCTL(APPLET_NOEXEC(sysctl, sysctl, BB_DIR_SBIN, BB_SUID_DROP, sysctl))
IF_TOP(APPLET(top, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UPTIME(APPLET_NOEXEC(uptime, uptime, BB_DIR_USR_BIN, BB_SUID_DROP, uptime))
IF_WATCH(APPLET(watch, BB_DIR_BIN, BB_SUID_DROP))
IF_CHPST(    APPLET_NOEXEC(chpst,     chpst, BB_DIR_USR_BIN, BB_SUID_DROP, chpst))
IF_ENVDIR(   APPLET_NOEXEC(envdir,    chpst, BB_DIR_USR_BIN, BB_SUID_DROP, envdir))
IF_ENVUIDGID(APPLET_NOEXEC(envuidgid, chpst, BB_DIR_USR_BIN, BB_SUID_DROP, envuidgid))
IF_SETUIDGID(APPLET_NOEXEC(setuidgid, chpst, BB_DIR_USR_BIN, BB_SUID_DROP, setuidgid))
IF_SOFTLIMIT(APPLET_NOEXEC(softlimit, chpst, BB_DIR_USR_BIN, BB_SUID_DROP, softlimit))
IF_RUNSV(APPLET(runsv, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_RUNSVDIR(APPLET(runsvdir, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SV( APPLET_NOEXEC(sv,  sv,  BB_DIR_USR_BIN, BB_SUID_DROP, sv ))
IF_SVC(APPLET_NOEXEC(svc, svc, BB_DIR_USR_BIN, BB_SUID_DROP, svc))
IF_SVLOGD(APPLET(svlogd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_CHCON(APPLET(chcon, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_GETENFORCE(APPLET(getenforce, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_GETSEBOOL(APPLET(getsebool, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_LOAD_POLICY(APPLET(load_policy, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_MATCHPATHCON(APPLET(matchpathcon, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_RUNCON(APPLET(runcon, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SELINUXENABLED(APPLET(selinuxenabled, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SESTATUS(APPLET(sestatus, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SETENFORCE(APPLET(setenforce, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SETFILES(APPLET(setfiles, BB_DIR_SBIN, BB_SUID_DROP))
IF_RESTORECON(APPLET_ODDNAME(restorecon, setfiles, BB_DIR_SBIN, BB_SUID_DROP, restorecon))
IF_SETSEBOOL(APPLET(setsebool, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_ASH(APPLET(ash, BB_DIR_BIN, BB_SUID_DROP))
IF_SH_IS_ASH(  APPLET_ODDNAME(sh,   ash, BB_DIR_BIN, BB_SUID_DROP, ash))
IF_BASH_IS_ASH(APPLET_ODDNAME(bash, ash, BB_DIR_BIN, BB_SUID_DROP, ash))
IF_CTTYHACK(APPLET_NOEXEC(cttyhack, cttyhack, BB_DIR_BIN, BB_SUID_DROP, cttyhack))
IF_HUSH(APPLET(hush, BB_DIR_BIN, BB_SUID_DROP))
IF_SH_IS_HUSH(  APPLET_ODDNAME(sh,   hush, BB_DIR_BIN, BB_SUID_DROP, hush))
IF_BASH_IS_HUSH(APPLET_ODDNAME(bash, hush, BB_DIR_BIN, BB_SUID_DROP, hush))
IF_KLOGD(APPLET(klogd, BB_DIR_SBIN, BB_SUID_DROP))
IF_LOGGER(APPLET(logger, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_LOGREAD(APPLET(logread, BB_DIR_SBIN, BB_SUID_DROP))
IF_SYSLOGD(APPLET(syslogd, BB_DIR_SBIN, BB_SUID_DROP))
IF_ACPID(APPLET(acpid, BB_DIR_SBIN, BB_SUID_DROP))
IF_BLKDISCARD(APPLET_NOEXEC(blkdiscard, blkdiscard, BB_DIR_USR_BIN, BB_SUID_DROP, blkdiscard))
IF_BLKID(APPLET_NOEXEC(blkid, blkid, BB_DIR_SBIN, BB_SUID_DROP, blkid))
IF_BLOCKDEV(APPLET_NOEXEC(blockdev, blockdev, BB_DIR_SBIN, BB_SUID_DROP, blockdev))
IF_CAL(APPLET(cal, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_CHRT(APPLET_NOEXEC(chrt, chrt, BB_DIR_USR_BIN, BB_SUID_DROP, chrt))
IF_DMESG(APPLET(dmesg, BB_DIR_BIN, BB_SUID_DROP))
IF_EJECT(APPLET(eject, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_FALLOCATE(APPLET(fallocate, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_FATATTR(APPLET_NOEXEC(fatattr, fatattr, BB_DIR_BIN, BB_SUID_DROP, fatattr))
IF_FBSET(APPLET(fbset, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FDFORMAT(APPLET(fdformat, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_FDISK(APPLET(fdisk, BB_DIR_SBIN, BB_SUID_DROP))
IF_FINDFS(APPLET(findfs, BB_DIR_SBIN, BB_SUID_MAYBE))
IF_FLOCK(APPLET(flock, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_FDFLUSH(   APPLET_ODDNAME(fdflush,     freeramdisk, BB_DIR_BIN,  BB_SUID_DROP, fdflush    ))
IF_FREERAMDISK(APPLET_NOEXEC(freeramdisk, freeramdisk, BB_DIR_SBIN, BB_SUID_DROP, freeramdisk))
IF_FSCK_MINIX(APPLET_ODDNAME(fsck.minix, fsck_minix, BB_DIR_SBIN, BB_SUID_DROP, fsck_minix))
IF_FSFREEZE(APPLET_NOEXEC(fsfreeze, fsfreeze, BB_DIR_USR_SBIN, BB_SUID_DROP, fsfreeze))
IF_FSTRIM(APPLET_NOEXEC(fstrim, fstrim, BB_DIR_SBIN, BB_SUID_DROP, fstrim))
IF_GETOPT(APPLET_NOEXEC(getopt, getopt, BB_DIR_BIN, BB_SUID_DROP, getopt))
IF_HEXDUMP(APPLET_NOEXEC(hexdump, hexdump, BB_DIR_USR_BIN, BB_SUID_DROP, hexdump))
IF_HD(APPLET_NOEXEC(hd, hexdump, BB_DIR_USR_BIN, BB_SUID_DROP, hd))
IF_XXD(APPLET_NOEXEC(xxd, xxd, BB_DIR_USR_BIN, BB_SUID_DROP, xxd))
IF_HWCLOCK(APPLET(hwclock, BB_DIR_SBIN, BB_SUID_DROP))
IF_IONICE(APPLET_NOEXEC(ionice, ionice, BB_DIR_BIN, BB_SUID_DROP, ionice))
IF_IPCRM(APPLET_NOEXEC(ipcrm, ipcrm, BB_DIR_USR_BIN, BB_SUID_DROP, ipcrm))
IF_IPCS(APPLET_NOEXEC(ipcs, ipcs, BB_DIR_USR_BIN, BB_SUID_DROP, ipcs))
IF_LAST(APPLET(last, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_LOSETUP(APPLET_NOEXEC(losetup, losetup, BB_DIR_SBIN, BB_SUID_DROP, losetup))
IF_LSPCI(APPLET_NOEXEC(lspci, lspci, BB_DIR_USR_BIN, BB_SUID_DROP, lspci))
IF_LSUSB(APPLET_NOEXEC(lsusb, lsusb, BB_DIR_USR_BIN, BB_SUID_DROP, lsusb))
IF_MDEV(APPLET(mdev, BB_DIR_SBIN, BB_SUID_DROP))
IF_MESG(APPLET_NOFORK(mesg, mesg, BB_DIR_USR_BIN, BB_SUID_DROP, mesg))
IF_MKE2FS(   APPLET_ODDNAME(mke2fs,    mkfs_ext2, BB_DIR_SBIN, BB_SUID_DROP, mkfs_ext2))
IF_MKFS_EXT2(APPLET_ODDNAME(mkfs.ext2, mkfs_ext2, BB_DIR_SBIN, BB_SUID_DROP, mkfs_ext2))
IF_MKFS_MINIX(APPLET_ODDNAME(mkfs.minix, mkfs_minix, BB_DIR_SBIN, BB_SUID_DROP, mkfs_minix))
IF_MKFS_REISER(APPLET_ODDNAME(mkfs.reiser, mkfs_reiser, BB_DIR_SBIN, BB_SUID_DROP, mkfs_reiser))
IF_MKDOSFS(  APPLET_ODDNAME(mkdosfs,   mkfs_vfat, BB_DIR_SBIN, BB_SUID_DROP, mkfs_vfat))
IF_MKFS_VFAT(APPLET_ODDNAME(mkfs.vfat, mkfs_vfat, BB_DIR_SBIN, BB_SUID_DROP, mkfs_vfat))
IF_MKSWAP(APPLET(mkswap, BB_DIR_SBIN, BB_SUID_DROP))
IF_MORE(APPLET(more, BB_DIR_BIN, BB_SUID_DROP))
IF_MOUNT(APPLET(mount, BB_DIR_BIN, IF_DESKTOP(BB_SUID_MAYBE) IF_NOT_DESKTOP(BB_SUID_DROP)))
IF_MOUNTPOINT(APPLET_NOEXEC(mountpoint, mountpoint, BB_DIR_BIN, BB_SUID_DROP, mountpoint))
IF_NSENTER(APPLET(nsenter, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_PIVOT_ROOT(APPLET_NOFORK(pivot_root, pivot_root, BB_DIR_SBIN, BB_SUID_DROP, pivot_root))
IF_RDATE(APPLET(rdate, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_RDEV(APPLET_NOEXEC(rdev, rdev, BB_DIR_USR_SBIN, BB_SUID_DROP, rdev))
IF_READPROFILE(APPLET(readprofile, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_RENICE(APPLET_NOEXEC(renice, renice, BB_DIR_USR_BIN, BB_SUID_DROP, renice))
IF_REV(APPLET(rev, BB_DIR_BIN, BB_SUID_DROP))
IF_RTCWAKE(APPLET(rtcwake, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_SCRIPT(APPLET(script, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SCRIPTREPLAY(APPLET(scriptreplay, BB_DIR_BIN, BB_SUID_DROP))
IF_SETARCH(APPLET_NOEXEC(setarch, setarch, BB_DIR_BIN, BB_SUID_DROP, setarch))
IF_LINUX32(APPLET_NOEXEC(linux32, setarch, BB_DIR_BIN, BB_SUID_DROP, linux32))
IF_LINUX64(APPLET_NOEXEC(linux64, setarch, BB_DIR_BIN, BB_SUID_DROP, linux64))
IF_SETPRIV(APPLET(setpriv, BB_DIR_BIN, BB_SUID_DROP))
IF_SETSID(APPLET(setsid, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_SWAPON( APPLET_ODDNAME(swapon,  swap_on_off, BB_DIR_SBIN, BB_SUID_DROP, swapon))
IF_SWAPOFF(APPLET_ODDNAME(swapoff, swap_on_off, BB_DIR_SBIN, BB_SUID_DROP, swapoff))
IF_SWITCH_ROOT(APPLET(switch_root, BB_DIR_SBIN, BB_SUID_DROP))
IF_RUN_INIT(   APPLET_ODDNAME(run-init, switch_root, BB_DIR_SBIN, BB_SUID_DROP, run_init))
IF_TASKSET(APPLET_NOEXEC(taskset, taskset, BB_DIR_USR_BIN, BB_SUID_DROP, taskset))
IF_UEVENT(APPLET(uevent, BB_DIR_SBIN, BB_SUID_DROP))
IF_UMOUNT(APPLET_NOEXEC(umount, umount, BB_DIR_BIN, BB_SUID_DROP, umount))
IF_UNSHARE(APPLET(unshare, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_WALL(APPLET(wall, BB_DIR_USR_BIN, BB_SUID_REQUIRE))
IF_UDHCPC6(APPLET(udhcpc6, BB_DIR_USR_BIN, BB_SUID_DROP))
IF_UDHCPC(APPLET(udhcpc, BB_DIR_SBIN, BB_SUID_DROP))
IF_UDHCPD(APPLET(udhcpd, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_DHCPRELAY(APPLET(dhcprelay, BB_DIR_USR_SBIN, BB_SUID_DROP))
IF_DUMPLEASES(APPLET_NOEXEC(dumpleases, dumpleases, BB_DIR_USR_BIN, BB_SUID_DROP, dumpleases))
IF_DHCP6C(APPLET(dhcp6c, BB_DIR_SBIN, BB_SUID_DROP))


#if !defined(PROTOTYPES) && !defined(NAME_MAIN) && !defined(MAKE_USAGE) \
	&& !defined(MAKE_LINKS) && !defined(MAKE_SUID)
};
#endif

#undef APPLET
#undef APPLET_ODDNAME
#undef APPLET_NOEXEC
#undef APPLET_NOFORK
