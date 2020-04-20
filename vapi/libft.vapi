/* libft.vapi
 *
 * Copyright 2020 Paulo Queiroz <pvaqueiroz@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

[CCode (cprefix = "ft_",
	lower_case_cprefix = "ft_", cheader_filename = "libft.h")]
namespace Libft
{
	/*
	** put =====================================================================
	*/

	public void putchar_fd(char c, int fd);
	public void putchar(char c);
	public void putendl_fd(string s, int fd);
	public void putendl(string s);
	public void putnbr_fd(int n, int fd);
	public void putnbr(int n);
	public void putstr_fd(string s, int fd);
	public void putstr(string s);

	/*
	** str =====================================================================
	*/

	public size_t strlen(string s);
	public string strdup(string s);
	public string strdupchr(string s, char c);
	public unowned string? strchr(string s, char c);
	public string strjoin(string s1, string s2);

	public int strcmp(string s1, string s2);
	public bool strequ(string s1, string s2);
	public int strncmp(string s1, string s2, size_t n);
	public bool strnequ(string s1, string s2, size_t n);

	/*
	** printf ==================================================================
	*/

	[PrintfFormat]
	public int printf(string fmt, ...);

	[PrintfFormat]
	public String sprintf(string fmt, ...);

	[PrintfFormat]
	public int dprintf(int fd, string fmt, ...);

	/*
	** Classes =================================================================
	*/

	[CCode (cname = "e_string_grow", has_type_id = false,
		cprefix = "T_STRING_GROWMODE_")]
	public enum StringGrowmode
	{
		FIXED,
		DOUBLE,
		QUADRATIC
	}

	[SimpleType]
	[CCode (cname = "t_string_cfg")]
	public struct StringConfig
	{
		public size_t extra;
		public short growmode;
	}

	[Compact]
	[CCode (cname = "t_string", cprefix = "ft_string_", has_type_id = false,
		free_function = "ft_string_free")]
	public class String
	{
		public string data;
		public size_t length;
		private size_t size;
		private StringConfig cfg;

		public String(string? s);
		[CCode (cname = "ft_string_clone")]
		public String.clone(String s);
		public String.n(string s, size_t len);

		public unowned string to_string()
		{
			return this.data;
		}

		public unowned String padding(size_t start, size_t len, char c);
		public unowned String remove(size_t start, size_t len);

		public void append(string s);
		public void appendn(string s, size_t len);
		public void real_append(String s);

		public void inpend(size_t index, string s);
		public void prepend(string s);

		public void to_lower();
		public void to_upper();
	}
}
