/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_harena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 01:50:00 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <harena.h>
#include <libft.h>
#include <string.h>

static int	total_tests = 0;
static int	passed_tests = 0;

#define TEST(name) do { \
	total_tests++; \
	ft_printf("Testing " name "... "); \
} while(0)

#define PASS() do { \
	passed_tests++; \
	ft_printf("PASS\n"); \
} while(0)

#define FAIL(msg) do { \
	ft_printf("FAIL: " msg "\n"); \
} while(0)

void	test_create_success(void)
{
	t_harena	h;

	TEST("harena_create success");
	h = harena_create(1024);
	if (h.base && h.offset == 0 && h.capacity == 1024)
		PASS();
	else
		FAIL("Expected valid base, offset=0, capacity=1024");
	harena_destroy(&h);
}

void	test_create_zero_size(void)
{
	t_harena	h;

	TEST("harena_create zero size");
	h = harena_create(0);
	if (h.base == NULL && h.capacity == 0)
		PASS();
	else
		FAIL("Expected NULL base and capacity=0");
}

void	test_create_malloc_failure(void)
{
	t_harena	h;

	TEST("harena_create malloc failure handling");
	h = harena_create(SIZE_MAX);
	if (h.base == NULL && h.capacity == 0)
		PASS();
	else
		FAIL("Expected NULL base on malloc failure");
}

void	test_alloc_basic(void)
{
	t_harena	h;
	void		*ptr;
	int			*val;

	TEST("harena_alloc basic allocation");
	h = harena_create(1024);
	ptr = harena_alloc(&h, sizeof(int));
	if (ptr)
	{
		val = (int *)ptr;
		*val = 42;
		if (*val == 42)
			PASS();
		else
			FAIL("Data write/read failed");
	}
	else
		FAIL("Allocation returned NULL");
	harena_destroy(&h);
}

void	test_alloc_alignment(void)
{
	t_harena	h;
	void		*ptr1, *ptr2;
	size_t		align1, align2;

	TEST("harena_alloc 8-byte alignment");
	h = harena_create(1024);
	ptr1 = harena_alloc(&h, 1);
	ptr2 = harena_alloc(&h, 1);
	if (ptr1 && ptr2)
	{
		align1 = (size_t)ptr1 % 8;
		align2 = (size_t)ptr2 % 8;
		if (align1 == 0 && align2 == 0)
			PASS();
		else
			FAIL("Pointer not 8-byte aligned");
	}
	else
		FAIL("Allocation returned NULL");
	harena_destroy(&h);
}

void	test_alloc_multiple(void)
{
	t_harena	h;
	void		*ptrs[10];
	int			i;

	TEST("harena_alloc multiple allocations");
	h = harena_create(1024);
	for (i = 0; i < 10; i++)
		ptrs[i] = harena_alloc(&h, 16);
	if (ptrs[0] && ptrs[9])
	{
		for (i = 0; i < 10; i++)
			*(int *)ptrs[i] = i;
		PASS();
	}
	else
		FAIL("Allocation returned NULL");
	harena_destroy(&h);
}

void	test_alloc_full(void)
{
	t_harena	h;
	void		*ptr;

	TEST("harena_alloc full arena");
	h = harena_create(32);
	ptr = harena_alloc(&h, 40);
	if (ptr == NULL)
		PASS();
	else
		FAIL("Expected NULL on full arena");
	harena_destroy(&h);
}

void	test_alloc_null_arena(void)
{
	void	*ptr;

	TEST("harena_alloc NULL arena");
	ptr = harena_alloc(NULL, 16);
	if (ptr == NULL)
		PASS();
	else
		FAIL("Expected NULL for NULL arena");
}

void	test_alloc_zero_bytes(void)
{
	t_harena	h;
	void		*ptr;

	TEST("harena_alloc zero bytes");
	h = harena_create(1024);
	ptr = harena_alloc(&h, 0);
	if (ptr == NULL)
		PASS();
	else
		FAIL("Expected NULL for zero bytes");
	harena_destroy(&h);
}

void	test_calloc_basic(void)
{
	t_harena	h;
	int			*ptr;

	TEST("harena_calloc basic allocation");
	h = harena_create(1024);
	ptr = (int *)harena_calloc(&h, sizeof(int));
	if (ptr && *ptr == 0)
		PASS();
	else
		FAIL("Expected zero-initialized memory");
	harena_destroy(&h);
}

void	test_calloc_null_arena(void)
{
	void	*ptr;

	TEST("harena_calloc NULL arena");
	ptr = harena_calloc(NULL, sizeof(int));
	if (ptr == NULL)
		PASS();
	else
		FAIL("Expected NULL for NULL arena");
}

void	test_save_restore(void)
{
	t_harena	h;
	size_t		snapshot;
	int			*ptr1, *ptr2;

	TEST("harena_save and harena_restore");
	h = harena_create(1024);
	ptr1 = (int *)harena_alloc(&h, sizeof(int));
	snapshot = harena_save(&h);
	ptr2 = (int *)harena_alloc(&h, sizeof(int));
	*ptr1 = 10;
	*ptr2 = 20;
	harena_restore(&h, snapshot);
	ptr2 = (int *)harena_alloc(&h, sizeof(int));
	*ptr2 = 30;
	if (*ptr1 == 10 && *ptr2 == 30)
		PASS();
	else
		FAIL("Save/restore failed");
	harena_destroy(&h);
}

void	test_save_null_arena(void)
{
	size_t	snapshot;

	TEST("harena_save NULL arena");
	snapshot = harena_save(NULL);
	if (snapshot == 0)
		PASS();
	else
		FAIL("Expected 0 for NULL arena");
}

void	test_restore_null_arena(void)
{
	TEST("harena_restore NULL arena");
	harena_restore(NULL, 0);
	PASS();
}

void	test_reset(void)
{
	t_harena	h;
	int			*ptr1, *ptr2;

	TEST("harena_reset");
	h = harena_create(1024);
	ptr1 = (int *)harena_alloc(&h, sizeof(int));
	*ptr1 = 42;
	harena_reset(&h);
	ptr2 = (int *)harena_alloc(&h, sizeof(int));
	*ptr2 = 100;
	if (*ptr2 == 100)
		PASS();
	else
		FAIL("Reset failed");
	harena_destroy(&h);
}

void	test_reset_null_arena(void)
{
	TEST("harena_reset NULL arena");
	harena_reset(NULL);
	PASS();
}

void	test_destroy(void)
{
	t_harena	h;

	TEST("harena_destroy");
	h = harena_create(1024);
	harena_destroy(&h);
	if (h.base == NULL && h.capacity == 0 && h.offset == 0)
		PASS();
	else
		FAIL("Destroy didn't clean struct");
}

void	test_destroy_null_arena(void)
{
	TEST("harena_destroy NULL arena");
	harena_destroy(NULL);
	PASS();
}

void	test_alloc_after_reset(void)
{
	t_harena	h;
	int			*ptr;
	int			i;

	TEST("harena_alloc after reset");
	h = harena_create(1024);
	for (i = 0; i < 10; i++)
		harena_alloc(&h, 16);
	harena_reset(&h);
	ptr = (int *)harena_alloc(&h, sizeof(int));
	*ptr = 99;
	if (*ptr == 99)
		PASS();
	else
		FAIL("Alloc after reset failed");
	harena_destroy(&h);
}

	int	main(void)
{
	ft_printf("=== Arena Allocator Tests ===\n\n");
	test_create_success();
	test_create_zero_size();
	test_create_malloc_failure();
	test_alloc_basic();
	test_alloc_alignment();
	test_alloc_multiple();
	test_alloc_full();
	test_alloc_null_arena();
	test_alloc_zero_bytes();
	test_calloc_basic();
	test_calloc_null_arena();
	test_save_restore();
	test_save_null_arena();
	test_restore_null_arena();
	test_reset();
	test_reset_null_arena();
	test_destroy();
	test_destroy_null_arena();
	test_alloc_after_reset();
	ft_printf("\n=== Results: %d/%d tests passed ===\n", passed_tests, total_tests);
	return (passed_tests == total_tests ? 0 : 1);
}
